#include <iostream>
#include <stdexcept>

class BadOptionalAccess : public std::exception
{
public:
    const char* what() const noexcept override
    {
        return "BadOptionalAccess";
    }
};

template<typename T>
class Optional
{
private:
    alignas(T) char storage[sizeof(T)];
    bool hasValue;

public:
    Optional() : hasValue(false) {}

    Optional(const T& value) : hasValue(true)
    {
        new (storage) T(value);
    }

    Optional(const Optional& other) : hasValue(other.hasValue)
    {
        if (hasValue)
        {
            new (storage) T(*other);
        }
    }

    template<typename U>
    Optional(const Optional<U>& other) : hasValue(other.has_value())
    {
        if (hasValue)
        {
            new (storage) T(other.value());
        }
    }

    Optional& operator=(const Optional& other)
    {
        if (this != &other)
        {
            reset();
            hasValue = other.hasValue;
            if (hasValue)
            {
                new (storage) T(*other);
            }
        }
        return *this;
    }

    ~Optional()
    {
        reset();
    }

    bool has_value() const
    {
        return hasValue;
    }

    T& operator*()
    {
        return *reinterpret_cast<T*>(storage);
    }

    const T& operator*() const
    {
        return *reinterpret_cast<const T*>(storage);
    }

    T& value()
    {
        if (!hasValue) throw BadOptionalAccess();
        return **this;
    }

    const T& value() const
    {
        if (!hasValue) throw BadOptionalAccess();
        return **this;
    }

    explicit operator bool() const
    {
        return hasValue;
    }

    void reset()
    {
        if (hasValue)
        {
            reinterpret_cast<T*>(storage)->~T();
            hasValue = false;
        }
    }

    T value_or(const T& default_value) const
    {
        return hasValue ? **this : default_value;
    }
};
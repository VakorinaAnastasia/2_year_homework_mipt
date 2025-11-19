#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Number 
{
private:
    static const int base = 100;
    char* data;
    std::size_t size;
    std::size_t capacity;

    void resize(std::size_t new_capacity) 
    {
        char* new_data = new char[new_capacity];
        for (std::size_t i = 0; i < size; ++i) 
        {
            new_data[i] = data[i];
        }
        for (std::size_t i = size; i < new_capacity; ++i) 
        {
            new_data[i] = 0;
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    void removeLeadingZeros() 
    {
        while (size > 1 && data[size - 1] == 0) 
        {
            --size;
        }
    }

public:
    Number() 
    {
        capacity = 1;
        data = new char[capacity];
        data[0] = 0;
        size = 1;
    }

    Number(int a) 
    {
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        if (capacity == 0) 
            capacity = 1;

        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        size = capacity;
    }

    Number(const std::string& str) 
    {
        if (str.empty()) 
        {
            capacity = 1;
            data = new char[capacity];
            data[0] = 0;
            size = 1;
            return;
        }

        capacity = (str.length() + 1) / 2;
        if (capacity == 0) capacity = 1;
        data = new char[capacity];

        for (std::size_t i = 0; i < capacity; ++i) 
        {
            data[i] = 0;
        }

        size = 0;
        int current = 0;
        int multiplier = 1;

        for (int i = str.length() - 1; i >= 0; --i) 
        {
            char c = str[i];
            if (c >= '0' && c <= '9') 
            {
                current += (c - '0') * multiplier;
                multiplier *= 10;

                if (multiplier == base) 
                {
                    data[size] = current;
                    ++size;
                    current = 0;
                    multiplier = 1;
                }
            }
        }

        if (current != 0 || size == 0) 
        {
            data[size] = current;
            ++size;
        }

        removeLeadingZeros();
    }

    Number(const Number& other) 
    {
        capacity = other.capacity;
        size = other.size;
        data = new char[capacity];
        for (std::size_t i = 0; i < size; ++i) 
        {
            data[i] = other.data[i];
        }
    }

    Number& operator=(const Number& other) 
    {
        if (this != &other) 
        {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new char[capacity];
            for (std::size_t i = 0; i < size; ++i) 
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    ~Number() 
    {
        delete[] data;
    }

    Number operator+(const Number& other) const 
    {
        Number result = *this;
        result += other;
        return result;
    }

    Number& operator+=(const Number& other) 
    {
        std::size_t max_size = size > other.size ? size : other.size;
        if (max_size + 1 > capacity) 
        {
            resize(max_size + 1);
        }

        int carry = 0;
        for (std::size_t i = 0; i < max_size || carry != 0; ++i) 
        {
            if (i >= size) 
            {
                if (i >= capacity) resize(capacity * 2);
                data[i] = 0;
                if (i >= size) size = i + 1;
            }

            int sum = data[i] + carry;
            if (i < other.size) sum += other.data[i];

            data[i] = sum % base;
            carry = sum / base;
        }

        removeLeadingZeros();
        return *this;
    }

    Number operator*(const Number& other) const 
    {
        Number result;
        result.resize(size + other.size + 1);

        for (std::size_t i = 0; i < size; ++i) 
        {
            int carry = 0;
            for (std::size_t j = 0; j < other.size || carry != 0; ++j) 
            {
                long long product = result.data[i + j] + 
                                  static_cast<long long>(data[i]) * 
                                  (j < other.size ? other.data[j] : 0) + 
                                  carry;
                
                result.data[i + j] = product % base;
                carry = product / base;
                
                if (i + j >= result.size) result.size = i + j + 1;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    bool isEven() const 
    {
        return (data[0] % 2) == 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    stream << static_cast<int>(num.data[num.size - 1]);
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);
    return stream;
}

class Integer 
{
private:
    static const int base = 100;
    std::vector<char> data;

    void removeLeadingZeros() 
    {
        while (data.size() > 1 && data.back() == 0) 
        {
            data.pop_back();
        }
    }

public:
    Integer() 
    {
        data.push_back(0);
    }

    Integer(int a) 
    {
        if (a == 0) 
        {
            data.push_back(0);
            return;
        }
        
        int temp = a;
        while (temp != 0) 
        {
            data.push_back(temp % base);
            temp /= base;
        }
    }

    Integer(const std::string& str) 
    {
        if (str.empty()) 
        {
            data.push_back(0);
            return;
        }

        data.resize((str.length() + 1) / 2, 0);
        
        int current = 0;
        int multiplier = 1;
        std::size_t index = 0;

        for (int i = str.length() - 1; i >= 0; --i) 
        {
            char c = str[i];
            if (c >= '0' && c <= '9') 
            {
                current += (c - '0') * multiplier;
                multiplier *= 10;

                if (multiplier == base) 
                {
                    data[index++] = current;
                    current = 0;
                    multiplier = 1;
                }
            }
        }

        if (current != 0 || index == 0) 
        {
            if (index >= data.size()) data.push_back(current);
            else data[index] = current;
        }

        removeLeadingZeros();
    }

    Integer operator+(const Integer& other) const 
    {
        Integer result = *this;
        result += other;
        return result;
    }

    Integer& operator+=(const Integer& other) 
    {
        std::size_t max_size = data.size() > other.data.size() ? data.size() : other.data.size();
        data.resize(max_size + 1, 0);

        int carry = 0;
        for (std::size_t i = 0; i < max_size || carry != 0; ++i) 
        {
            int sum = data[i] + carry;
            if (i < other.data.size()) sum += other.data[i];

            data[i] = sum % base;
            carry = sum / base;
        }

        removeLeadingZeros();
        return *this;
    }

    Integer operator*(const Integer& other) const 
    {
        Integer result;
        result.data.resize(data.size() + other.data.size() + 1, 0);

        for (std::size_t i = 0; i < data.size(); ++i) 
        {
            int carry = 0;
            for (std::size_t j = 0; j < other.data.size() || carry != 0; ++j) 
            {
                long long product = result.data[i + j] + 
                                  static_cast<long long>(data[i]) * 
                                  (j < other.data.size() ? other.data[j] : 0) + 
                                  carry;
                
                result.data[i + j] = product % base;
                carry = product / base;
            }
        }

        result.removeLeadingZeros();
        return result;
    }

    bool isEven() const 
    {
        return (data[0] % 2) == 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Integer& num);
};

std::ostream& operator<<(std::ostream& stream, const Integer& num)
{
    stream << static_cast<int>(num.data[num.data.size() - 1]);
    for (std::size_t i = 0; i < num.data.size() - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.data.size() - 2 - i]);
    return stream;
}
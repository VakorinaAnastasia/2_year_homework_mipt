#include <iostream>

class RestrictWrapper
{
private:
    int& mValue;
    const int mMinValue;
    const int mMaxValue;
    int mGetCount;
    int mSetCount;

public:
    RestrictWrapper(int& value, int minValue, int maxValue)
        : mValue(value), mMinValue(minValue), mMaxValue(maxValue), mGetCount(0), mSetCount(0)
    {
    }
    
    int get()
    {
        mGetCount++;
        return mValue;
    }
    
    void set(int newValue)
    {
        mSetCount++;
        if (newValue < mMinValue) {
            mValue = mMinValue;
        } else if (newValue > mMaxValue) {
            mValue = mMaxValue;
        } else {
            mValue = newValue;
        }
    }
    
    int getCount() const
    {
        return mGetCount;
    }
    
    int setCount() const
    {
        return mSetCount;
    }
};

int main()
{
    int x = 100;
    RestrictWrapper v(x, 0, 300);
    std::cout << v.get() << std::endl;
    v.set(-200);
    std::cout << v.get() << std::endl;
    v.set(300);
    v.set(400);
    v.set(500);
    std::cout << v.get() << std::endl;

    std::cout << v.getCount() << std::endl;
    std::cout << v.setCount() << std::endl;
}
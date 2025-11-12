#include <iostream>

namespace mipt
{
    namespace fefm
    {
        struct Point
        {
            int x, y;
        };
    }

    namespace frtk
    {
        void print(fefm::Point p)
        {
            std::cout << p.x << " " << p.y << std::endl;
        }
    }
}

int main1()
{
    mipt::fefm::Point p = {10, 20};
    mipt::frtk::print(p);
}

using namespace mipt;
int main2()
{
    fefm::Point p = {10, 20};
    frtk::print(p);
}

using mipt::fefm::Point;
using mipt::frtk::print;
int main3()
{
    Point p = {10, 20};
    print(p);
}

int main()
{
    main1();
    main2();
    main3();
}

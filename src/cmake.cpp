#include <iostream>
#include "math.h"

using namespace math;
int main(int argc, const char *argv[])
{
    std::cout << "Hello C++ " << __cplusplus << std::endl;
    int a = 2, c = 4;
    std::cout << "add=" << math_add(a, c) << std::endl;

    return 0;
}
#include <iostream>
#include "BigInt.h"

#define cube(x) (x * x * x)

int main() {
//    BigInt a;
//    BigInt b;
//
//    std::cin >> a >> b;
//    std::cout << a + b << std::endl;
//    std::cout << (a == b) << std::endl;

    int a = 2;

    a = cube(++a);

    std::cout << a ;

    return 0;
}

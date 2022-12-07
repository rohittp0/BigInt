#include <iostream>
#include "BigInt.h"

int main() {
    BigInt a;
    BigInt b;

    std::cin >> a >> b;
    std::cout << a + b << std::endl;
    std::cout << (a == b) << std::endl;

    return 0;
}

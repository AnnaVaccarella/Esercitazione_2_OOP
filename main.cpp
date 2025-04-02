#include <iostream>
#include "complex_number.hpp"
//Test della classe
int main() {
    complex_number<double> n1(1, 2);
    complex_number<double> n2(3, -4);

    std::cout << "n1: " << n1 << std::endl;
    std::cout << "n2: " << n2 << std::endl;

    complex_number<double> n3 = n1 + n2;
    std::cout << "n1 + n2: " << n3 << std::endl;

    n1 += n2;
    std::cout << "Dopo n1 += n2: " << n1 << std::endl;

    complex_number<double> n4 = n1 * n2;
    std::cout << "n1 * n2: " << n4 << std::endl;

    n1 *= n2;
    std::cout << "Dopo n1 *= n2: " << n1 << std::endl;

    return 0;
}
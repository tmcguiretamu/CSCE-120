// Division example 2 w/assert()
#include <iostream>
#include <cassert>

double divide(int num, int den) {
    int quotient = num / den;
    return quotient;
}

int main() {
    double result = divide(6, 3);
    assert(("Incorrect calculation.", 2 == result));

    result = divide(3, 6);
    assert(("Integer division error.", 0.5 == result));

    return 0;
}

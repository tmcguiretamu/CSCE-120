// Division example 1 w/assert()
#include <iostream>
#include <cassert>


double divide(int num, int den) {
    int quotient = num / den;
    return quotient;
}

int main() {
    double result = divide(6, 3);
    assert(2 == result);

    result = divide(3, 6);
    assert(0.5 == result);

    return 0;
}

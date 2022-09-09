// Division example w/o assert()
#include <iostream>

using namespace std;

double divide(int numerator, int denominator) {
    int quotient = numerator/denominator;
    return quotient;
}

int main() {
    double result = divide(6, 3);
    if (2.0 != result) {
        cout<<"fail: divide(6, 3) = "<<result<<" != 2\n";
        return 1;
    }

    result = divide(3, 6);
    if (0.5 != result) {
        cout<<"fail: divide(3, 6) = "<<result<<" != 0.5\n";
        return 2;
    }

    return 0;
}

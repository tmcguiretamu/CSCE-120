#include <iostream>
using namespace std;

int main()
{
    int a = 2;
    switch (a)
    {
        case 0:
            cout<<"This is case a=0";
            break;
        case 1:
            cout<<"This is case a=1";
            break;
        case 2:
            cout<<"This is case a=2";
            break;
        default:
            cout<<"a > 2";
            break;
    }
    return 0;
}

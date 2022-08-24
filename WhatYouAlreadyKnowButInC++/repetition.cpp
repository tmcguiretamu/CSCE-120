#include <iostream>
using namespace std;

int main()
{
    for (int a = 2; a > 0; a--) {
        cout <<a<< "\n";
    }
    
    int b = 2;
    while (b>0) {
        cout<<b<<"\n";
        b--;
    }
    
    int c = 2;
    do {
        cout<<c<<"\n";
        c--;
    }
    while (c>0);

    return 0;
}

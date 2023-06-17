#include<iostream>
using namespace std;

void printBinary(int bin) {
    for(int i=31; i>=0; --i)
            cout << ((bin >> i) & 1);

    cout << endl;
}
int main() {
    int n, i;
    cin >> n >> i;
    printBinary(n);

    // check bit
    if(n & (1<<i) != 0)
        cout << "bit : 1" << endl;
    else
        cout << "bit : 0" << endl;

    // set bit
    printBinary(n | (1<<i));

    // unset bit
    printBinary(n & ~(1<<i));

    // toggle bit
    printBinary(n ^ (1<<i));

    // set bit count
    cout << "set bit count : " << __builtin_popcount(n) << endl;

    return 0;
}

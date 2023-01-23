#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

int a[100000];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i) 
        cin >> a[i];

    sort(a, a+n);
    int unfairness = INT_MAX;
    for(int i=0; i<=n-k; ++i) {
        unfairness = min(unfairness, a[i+k-1] - a[i]);
    }
    cout << unfairness << endl;
    return 0;
}
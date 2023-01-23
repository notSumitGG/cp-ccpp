#include<iostream>
#include<set>
using namespace std;

int a[10000];

int main() {
    int n, k;
    cin >> n >> k;
    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    set<int> keys;
    for(int i=0; i<n; ++i){
        if(i <= k)
            keys.insert(a[i]);
        else{
            cout << *keys.begin() << " ";
            keys.erase(keys.begin());
            keys.insert(a[i]);
        }
    }
    while(!keys.empty()){
        cout << *keys.begin() << " ";
        keys.erase(keys.begin());
    }
    cout << endl;
    return 0;
}
/* 7 3
6 5 3 2 8 10 9 */
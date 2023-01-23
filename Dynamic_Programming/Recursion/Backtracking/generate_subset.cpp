#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int s[64], n;
vector<int> subset;

void generate(vector<int> &subset, int i) {
    if(i == n){
        for(auto it : subset)
            cout << it << " ";
        cout << endl;
        return;
    }
    generate(subset, i+1);
    subset.push_back(s[i]);
    generate(subset, i+1);
    subset.pop_back();
    return;
}
int main() {
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
        scanf(" %d", &s[i]);

    generate(subset, 0);
    return 0;
}

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
    int n;
    stack<int> aux;
    cin >> n;
    vector<int> nums(n);
    vector<int> nge(n);
    
    for(int i=0; i<n; ++i) {
        cin >> nums[i];
        while(!aux.empty() && nums[aux.top()] < nums[i]) {
            nge[aux.top()] = nums[i];
            aux.pop();
        }
        aux.push(i);
    }
    while(!aux.empty()) {
        nge[aux.top()] = -1;
        aux.pop();
    }

    for(int i=0; i<n; ++i) 
        cout << nge[i] << " ";
    cout << endl;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
// https://cses.fi/problemset/task/1674/
#define N 10000
vector<int> tree[N];
void dfs(vector<int> &subord, int key, int par=0) {
    for(int child : tree[key]) {
        if(child == par) continue;
        dfs(subord, child, key);
        subord[key] += subord[child] + 1;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> subordinates(n+1);
    // 1st index is root given in the problem
    for(int i=2; i<=n; ++i) {
        int x;
        cin >> x;
        tree[i].push_back(x);
        tree[x].push_back(i);
    }
    dfs(subordinates, 1);
    for(int i=1; i<subordinates.size(); ++i)
        cout << subordinates[i] << " ";
    cout << endl;
    return 0;
}
/*5
1 1 2 3
*/
#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100000];
int sum[100000];

void dfs(int treenode, int parent=0) {
    sum[treenode] += treenode;
    for(int child : tree[treenode]) {
        if(child == parent) continue;

        dfs(child, treenode);
        sum[treenode] += sum[child];
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; ++i){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(1);
    for(int i=1; i<=n; ++i)
        cout << sum[i] << " ";
    cout << endl;
    return 0;
}
/* 13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11 */

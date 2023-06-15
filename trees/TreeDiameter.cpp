#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[100000];

void dfs(vector<int> &depth, int vertex, int parent = 0) {
    for(int child : tree[vertex]) {
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(depth, child, vertex);
    }
}
int main() {
    int n;
    cin >> n;
    {
    int a, b;
    for(int i=0; i<n-1; ++i) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    }
    vector<int> depth(n+1, 0);
    dfs(depth, 1);

    int max = 0, maxdepth = -1;
    for(int i=1; i<=n; ++i) {
        if(maxdepth < depth[i]) {
            maxdepth = depth[i];
            max = i;
        }
        depth[i] = 0;
    }

    dfs(depth, max);
    for(int i=1; i<=n; ++i)
        if(depth[max] < depth[i]) max = i;

    cout << depth[max] << endl;
    return 0;
}
// 14
// 1 2
// 1 3
// 1 13
// 2 5
// 5 6
// 5 7
// 5 8
// 8 12
// 3 4
// 4 9
// 4 10
// 10 11
// 12 14

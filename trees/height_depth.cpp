#include<iostream>
#include<vector>
using namespace std;

const int N = 10000;
vector<int> tree[N];
int height[N], depth[N];

void dfs(int vertex, int parent = 0) {
    for(int child : tree[vertex]) {
        if(child == parent) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child]+1);
    }
}
int main() {
    int n;
    cin >> n;
    for(int i=0; i<n-1; ++i) {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);
    for(int i=1; i<=n; ++i) {
        cout << depth[i] << " " << height[i] << endl;
    }
    return 0;
}

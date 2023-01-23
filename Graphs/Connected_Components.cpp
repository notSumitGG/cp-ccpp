#include<iostream>
#include<vector>
using namespace std;
// no-multi-edge non-weighted undirected graph
// adjacency list representation
const int N = 10000;
vector<int> graph[N];
bool visited[N];
int n, e;

void dfs(int vertex) {
    visited[vertex] = true;
    for(int neighbour : graph[vertex]) {
        if(visited[neighbour])  continue;

        dfs(neighbour);
    }
}
int main() {
    cin >> n >> e;
    for(int i=1; i<=e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int ct = 0;
    for(int i=1; i<=n; ++i) {
        if(visited[i]) continue;
        dfs(i);
        ct++;
    }
    cout << ct << endl;
    return 0;
}

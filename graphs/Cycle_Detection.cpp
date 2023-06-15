#include<iostream>
#include<vector>
using namespace std;
// no-multi-edge non-weighted undirected
const int N = 10000;
vector<int> graph[N];
bool visited[N];
int n, e;

int dfs(int vertex, int parent, int cycle) {
    visited[vertex] = true;
    for(int neighbour : graph[vertex]) {
        if(visited[neighbour] && neighbour == parent)  continue;
        if(visited[neighbour]) {
            cycle++;
            continue;
        }
        dfs(neighbour, vertex, cycle);
    }
    return cycle;
}
int main() {
    cin >> n >> e;
    for(int i=1; i<=e; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int cycle = 0;
    for(int i=1; i<=n; ++i) {
        if(!visited[i])
            cycle = dfs(i, 0, 0);
    }
    cout << cycle << endl;
    return 0;
}

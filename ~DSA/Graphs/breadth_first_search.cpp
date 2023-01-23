#include<iostream>
#include<queue>
#include<bitset>
#include<vector>
using namespace std;

#define N 10000
vector<int> graph[N];
bitset<N> visited(0);

void bfs(int key) {
    queue<int> q;
    q.push(key);
    visited |= 1<<key;
    while(!q.empty()) {
        int node = q.front();
        // cout << node << " ";
        q.pop();
        visited[node] = 1;      // visited.set(node, 1);
        for(int child : graph[node]) {
            if(visited[child]) continue;
            q.push(child);
            visited[child] = 1;
            // Your code here
        }
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i=1; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs(1);
    return 0;
}
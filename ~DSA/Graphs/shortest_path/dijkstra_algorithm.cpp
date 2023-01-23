#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

#define N 10000
vector<pair<int, int>> graph[N];

void dijkstra(int node) {
    vector<bool> visited(N, false);
    vector<int> distance(N, INT_MAX);
    priority_queue<pair<int, int>> pq;      // pair = total_weight, node

    pq.push({0, node});
    distance[node] = 0;

    while(pq.size() > 0) {
        auto min_node = pq.top();
        // int dis = min_node.first;
        int key = min_node.second;
        pq.pop();
        if(visited[key]) continue;
        visited[key] = true;
        for(auto child : graph[key]) {
            int child_key = child.first;
            int child_wt = child.second;
            if(distance[key] + child_wt < distance[child_key]) {
                distance[child_key] = distance[key] + child_wt;
                pq.push({distance[child_key], child_key});
            }
        }
    }
}
int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }   // weighted undirected graph
    int key;
    cin >> key;
    dijkstra(key);
    return 0;
}
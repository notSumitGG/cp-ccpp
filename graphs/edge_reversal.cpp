#include<iostream>
#include<vector>
#include<deque>
#include<limits.h>
using namespace std;
// https://www.codechef.com/problems/REVERSE?tab=statement
#define N 10000
vector<pair<int, int>> graph[N];
vector<int> lvl(N, INT_MAX);
// lvl[i] stores the number of edges needed to be reversed to reach destination node
// no visited array just because edges has two types of weights

// 0-1 bfs is implemented here
int bfs(int src, int n) {
    deque<int> dq;
    dq.push_back(src);
    lvl[src] = 0;

    while(!dq.empty()) {
        int cur = dq.front();
        dq.pop_front();

        for(auto &it : graph[cur]) {
            int child = it.first;
            int wt = it.second;
            if(lvl[cur] + wt < lvl[child]) {
                lvl[child] = lvl[cur] + wt;
                if(wt == 0)
                    dq.push_front(child);
                else
                    dq.push_back(child);
            }
        }
    }
    return lvl[n] == INT_MAX ? -1 : lvl[n];
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; ++i) {
        int x, y;
        cin >> x >> y;
        if(x == y) continue; // since the graph could contain self loops
        graph[x].push_back({y, false});
        graph[y].push_back({x, true});
    }
    cout << bfs(1, n) << endl;
    return 0;
}
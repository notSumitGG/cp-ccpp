#include<vector>
#include<iostream>
using namespace std;

//insert getancestor ht lvl path lca 

class tree {
    vector<int> lvl;
    vector<int> ht;
    vector<vector<int>> up;
    int LOG;

    void dfs(const vector<vector<int>> &t, int node, int parent = -1) {
        up[node][0] = parent;
        for(int i=1; i<LOG; ++i)
            up[node][i] = up[ up[node][i-1] ][i-1];

        for(int child : t[node]) {
            if(child == parent) continue;
            lvl[child] = lvl[node] + 1;
            dfs(t, child, node);
            ht[node] = max(ht[node], ht[child]+1);
        }
    }
public:
    tree(const vector<vector<int>> &t, int n, int root) {
        LOG = 0;
        while((1 << LOG) <= n)  LOG++;

        lvl = vector<int>(n);
        ht = vector<int>(n);
        up = vector<vector<int>>(n, vector<int>(LOG));
        dfs(t, root);

        // for(int i=0; i<n; ++i) {
        //     for(int j=0; j<LOG; ++i)
        //         cout << up[i][j];
        //     cout << endl;
        // }
    }

    int height(int key) {
        return ht[key];
    }

    int depth(int key) {
        return lvl[key];
    }

    int ancestor(int key, int k) {
        if(lvl[key] < k)
            return -1;
        
        for(int i=0; i<LOG; ++i) {
            if((1<<i) & k)
                key = up[key][i];
        }
        return key;
    }

    int lca(int u, int v) {
        if(lvl[u] < lvl[v])
            swap(u, v);
        int diff = lvl[u] - lvl[v];
        for(int i=0; i<LOG; ++i){
            if((1<<i) & diff)
                u = up[u][i];
        }
        if(u == v) return u;
        for(int i=LOG-1; i>=0; --i){
            if(up[u][i] != up[v][i]){
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> t(n, vector<int>());
    for(int i=1; i<n; ++i){
        int x, y;
        cin >> x >> y;
        // if(t[x].empty()) {
        //     t[x].push_back(-1);
        // }
        // t[x].push_back(y);
        // if(t[y].empty())
        //     t[y].push_back(0);
        // t[y][0] = x;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    tree ob = tree(t, n, 1);

    return 0;
}
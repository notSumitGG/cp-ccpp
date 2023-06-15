#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class dsu {
public:
    int parent[10000];
    // non made elements = 0
    // leader elements = -size
    // set elements = parent element
    void make_set(int key) {
        parent[key] = -1;
    }

    // finds root of the specified key
    int find_root(int key) {
        if(parent[key] < 0) return key;
        // path compression
        return parent[key] = find_root(parent[key]);
    }

    // merges two sets
    void union_sets(int k1, int k2) {
        k1 = find_root(k1);
        k2 = find_root(k2);
        
        if(k1 != k2) {
            if(-parent[k1] < -parent[k2])
                std::swap(k1, k2);
            parent[k1] += parent[k2];
            parent[k2] = k1;
        }
    }
};

int main() {
    dsu s;
    int n, e;
    cin >> n >> e;
    vector<pair<int, pair<int, int>>> edges;
    for(int i=0; i<e; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt;
        edges.push_back({wt, {x, y}});
    }
    for(int i=1; i<=n; ++i) 
        s.make_set(i);
    sort(edges.begin(), edges.end());
    int total_wt = 0;
    for(auto &e : edges) {
        int wt = e.first;
        int x = e.second.first;
        int y = e.second.second;
        if(s.find_root(x) == s.find_root(y)) continue;
        s.union_sets(x, y);
        total_wt += wt;
        cout << x << " " << y << " - " << wt << endl;
    }
    cout << total_wt << endl;
    return 0;
}
/*6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/

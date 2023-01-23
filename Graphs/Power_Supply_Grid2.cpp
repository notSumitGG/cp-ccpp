#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://codeforces.com/contest/1245/problem/D
#define ll long long
int n;
vector<pair<int, int>> cc; // city coords
vector<int> k; // cost of per km wire in ith city

ll total_cost = 0;
vector<int> ps; // powerstations built
vector<pair<int, int>> cxn; // connections made 

class dsu {
public:
    int parent[2000];
    int size_set[2000];
    // non made elements = 0
    // leader elements = key
    // set elements = parent element

    void make_set(int v) {
        parent[v] = v;
        size_set[v] = 1;
    }

    // finds root of the specified key
    int find_root(int v) {
        if(v == parent[v]) return v;
        // path compression
        return parent[v] = find_root(parent[v]);
    }

    // merges two sets
    void union_sets(int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if(a != b) {
            if(size_set[a] < size_set[b])
                std::swap(a, b);
            size_set[a] += size_set[b];
            parent[b] = a;
        }
    }
};

// luv solution optimized
int main() {
    cin >> n;
    cc = vector<pair<int, int>> (n+1);
    vector<int> c(n+1);
    k = vector<int> (n+1);
    vector<pair<ll, pair<int, int>>> edges;

    for(int i=0; i<n; ++i){
        cin >> cc[i].first >> cc[i].second;
    }
    for(int i=1; i<=n; ++i) {
        cin >> c[i];
        // connecting cost of cities to 0th edge
        edges.push_back({c[i], {0, i}});
    }
    for(int i=1; i<=n; ++i) {
        cin >> k[i];
    }
    for(int i=1; i<=n; ++i) {
        for(int j=i+1; j<=n; ++j) {
            int dis = abs(cc[i].first - cc[j].first) + abs(cc[i].second - cc[j].second);
            ll cst = dis * 1LL * (k[i] + k[j]);
            edges.push_back({cst, {i, j}});
        }
    }
    sort(edges.begin(), edges.end());

    dsu s;
    for(int i=1; i<=n; ++i) 
        s.make_set(i);
    for(auto &e : edges) {
        int wt = e.first;
        int x = e.second.first;
        int y = e.second.second;
        if(s.find_root(x) == s.find_root(y)) continue;
        s.union_sets(x, y);
        total_cost += wt;
        if(x == 0 || y == 0)
            ps.push_back(max(x, y));
        else 
            cxn.push_back({x, y});
    }

    cout << total_cost << endl;
    cout << ps.size() << endl;
    for(int i : ps) {
        cout << i << " ";
    }
    cout << endl << cxn.size() << endl;
    for(auto it : cxn) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
/*3
2 3
1 1
3 2
3 2 3
3 2 3
*/
/*3
2 1
1 2
3 3
23 2 23
3 2 3
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> tree[10000];
int parent[10000];

void dfs(int key, int par=-1){
    parent[key] = par;
    for(int child : tree[key]){
        if(child == par) continue;
        dfs(child, key);
    }
}

vector<int> path(int key) {
    vector<int> v;
    while(key != -1) {
        v.push_back(key);
        key = parent[key];
    }
    return v;
}

int main() {
    int n, x, y;
    cin >> n;
    for(int i=1; i<n; ++i) {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1);
    cin >> x >> y;
    vector<int> k1 = path(x);
    vector<int> k2 = path(y);

    vector<int> :: iterator it1 = k1.end()-1;
    vector<int> :: iterator it2 = k2.end()-1;
    
    while(*it1 == *it2){
        --it1;
        --it2;
    }
    cout << *(++it1) << endl;
}
/* 13
1 2
1 3
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9
4 10
10 11
6 7 */

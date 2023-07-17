#include<iostream>
#include<vector>
using namespace std;

vector<int> g[10000];
int color[10000]; // will be storing vertices marked with certain color
int n, e, c;

bool isSafe(int v, int c) {
    for (int i : g[v])
        if (c == color[i])
            return false;
 
    return true;
}

bool graph_coloring(int v, int m) {
    if(v==n) 
        return true;
    
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graph_coloring(v+1, m) == true)
                return true;
            color[v] = 0;
        }
    }

    return false;
}

int main() {
    // color c is taken as integer
    // and the colors will be 1, 2, 3 and so on...
    cin >> n >> e >> c;
    for(int i=0; i<e; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    // for(int i=0; i<=n; ++i) {
    //     color[i] = 0;
    // }
    // 0 is the first vertex
    if (graph_coloring(0, c)) {
        for(int i=0; i<n; ++i) 
            cout << color[i] << " ";
        cout << endl;   
    } else 
        cout << "The given graph can't be colored with " << c << " colors\n";
    return 0;
}

/*
4 4 2
0 1
1 2
2 3
3 0
*/
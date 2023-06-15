#include<iostream>
#include<limits.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
// https://www.codechef.com/SNCKPB17/problems/SNSOCIAL/
// this solution runs on multi source bfs

#define N 1000
int val[N][N];
int lev[N][N];
int n, m;

vector<pair<int, int>> mvmt = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, -1}, {-1, 1}, {1, 1}, {-1, -1}
};

bool isValid(int i, int j) {
    return i>=0 && j>=0 && i<n && j<m;
}
// multi-source bfs
int bfs(int mx) {
    queue<pair<int, int>> q;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            if(mx == val[i][j]) {
                q.push({i, j});
                lev[i][j] = 0;
            } else {
                lev[i][j] = -1;
            }
        }
    }
    int ans = 0;
    while(!q.empty()) {
        auto v = q.front();
        int x = v.first;
        int y = v.second;
        q.pop();
        for(auto move : mvmt) {
            int cx = move.first + x;
            int cy = move.second + y;
            if(!isValid(cx, cy)) continue;
            if(lev[cx][cy] != -1) continue;
            q.push({cx, cy});
            lev[cx][cy] = lev[x][y] + 1;
            ans = max(ans, lev[cx][cy]);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int mx = INT_MIN;
        cin >> n >> m;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                cin >> val[i][j];
                mx = max(mx, val[i][j]);
            }
        }
        cout << bfs(mx) << endl;
    }
    return 0;
}
/*3
2 2
1 1
1 1
2 2
1 1
1 2
3 4
1 2 1 2
1 1 1 2
1 1 2 2
*/

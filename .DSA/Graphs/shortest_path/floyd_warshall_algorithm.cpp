#include<iostream>
#include<limits.h>
using namespace std;

#define N 510
int dis[N][N];

int main() {
    for(int i=0; i<N; ++i) {
        for(int j=0; j<N; ++i) {
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INT_MAX;
        }
    }
    int n, e;
    cin >> n >> e;
    for(int i=0; i<e; ++i) {
        int x, y;
        cin >> x >> y;
        cin >> dis[x][y];
        // dis[y][x] = dis[x][y] for undirected
    }
    for(int k=1; k<=n; ++k) {
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX)
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            if(dis[i][j] == INT_MAX)
                cout << "I ";
            else 
                cout << dis[i][j];
        }
    }
    return 0;
}
/*6 9
1 2 1
1 3 5
2 3 2
3 5 2
2 5 1
2 4 2
4 5 3
4 6 1
5 6 2
*/

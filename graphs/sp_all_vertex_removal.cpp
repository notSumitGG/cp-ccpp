#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
// https://codeforces.com/problemset/problem/295/B

#define N 510
#define ll long long
ll dis[N][N];

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            cin >> dis[i][j];
        }
    }

    vector<int> rmv(n);
    for(int i=0; i<n; ++i)
        cin >> rmv[i];
    reverse(rmv.begin(), rmv.end());

    vector<ll> ans;
    for(int k=0; k<n; ++k) {
        int v = rmv[k];
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                ll new_dis = dis[i][v]+dis[v][j];
                dis[i][j] = min(dis[i][j], new_dis);
            }
        }
        ll sum = 0;
        for(int i=0; i<=k; ++i) {
            for(int j=0; j<=k; ++j) {
                sum += dis[rmv[i]][rmv[j]];
            }
        }
        ans.push_back(sum);
    }
    
    for(auto it=ans.end()-1; it>=ans.begin(); --it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
/*4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3
*/
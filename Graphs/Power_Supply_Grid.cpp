#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// https://codeforces.com/contest/1245/problem/D
#define ll long long
int n;
vector<pair<int, int>> cc; // city coords
vector<vector<int>> cost; // cost[i][i] = building powerstation in ith city
vector<int> k; // cost of per km wire in ith city

ll total_cost = 0;
vector<int> ps; // powerstations built
vector<pair<int, int>> cxn; // connections made 

// my solution
int main() {
    cin >> n;
    cc = vector<pair<int, int>> (n+1);
    cost = vector<vector<int>> (n+1, vector<int> (n+1));
    k = vector<int> (n+1);

    for(int i=0; i<n; ++i){
        cin >> cc[i].first >> cc[i].second;
    }
    for(int i=1; i<=n; ++i) {
        cin >> cost[i][i];
    }
    for(int i=1; i<=n; ++i) {
        cin >> k[i];
    }

    for(int i=1; i<=n; ++i) {
        int min_i = i, min_j = i;
        for(int j=1; j<=n; ++j) {
            if(i == j) continue;
            // cost for making a connection from i to j 
            cost[i][j] = (k[i] + k[j]) * (abs(cc[i].first - cc[j].first) + abs(cc[i].second - cc[j].second));
            if(cost[min_i][min_j] > cost[i][j]) {
                min_i = i;
                min_j = j;
            }
        }
        total_cost += cost[min_i][min_j];
        if(min_i == min_j)
            ps.push_back(min_i);
        else 
            cxn.push_back({min_i, min_j});
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
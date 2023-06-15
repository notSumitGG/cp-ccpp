#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;
    vector<vector<int>> arr(n);
    cin >> n >> q;

    while(q--){
        int c;
        int x, y;
        cin >> c >> x >> y;

        vector<vector<int>> arr(n, vector<int>());
        int last = 0;
        vector<int> ans;
        for(int i = 0; i < queries.size();i++){
            int x = queries[i][1];
            int y = queries[i][2];
            int index = (x ^ last) % n;
            if (queries[i][0] == 1) {
            arr[index].push_back(y);
            }else if (queries[i][0] == 2){
                last = arr[index][y % arr[index].size()];
                ans.push_back(last);
            }
        }
    }
    return 0;
}

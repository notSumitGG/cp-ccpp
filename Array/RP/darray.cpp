#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q, lastAnswer = 0;
    cin >> n >> q;
    vector<vector<int>> arr(n, vector<int> ());

    while(q--){
        int c;
        int x, y;
        cin >> c >> x >> y;

        int idx = (x ^ lastAnswer) % n;
        if(c == 1){
            arr[idx].push_back(y);
        }
        else if(c == 2){
            lastAnswer = arr[idx][y % arr[idx].size()];
            cout << lastAnswer << endl;
        }
    }
    return 0;
}

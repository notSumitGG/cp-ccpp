#include<iostream>
using namespace std;
// Given a string of lower case English alphabet of length N and two integers
// L and R he wants to know whether all the letters of the substring from index
// L to R(L and R included) can be rearranged to from a palindrome or not. He
// wants to know this for Q values of L and R and needs your help in finding
// the answer
// Constraints
// 1 <= t <= 10
// 1 <= N, Q <= 10^5
// 1 <= L <= R <= N 
int dp[96][10000];  // hash array

int main() {
    string a;
    int n, q;
    cin >> a >> q;
    n = a.size();
    // pre computation + hashing
    for(int i=0; i<96; ++i){
        if(a[0] - 32) ++dp[i][0];
        for(int j=1; j<n; ++j){
            dp[i][j] = dp[i][j-1];
            if(a[j] == i)
                ++dp[i][j];
        }
    }

    int l, r;
    while(q--) {
        cin >> l >> r;
        int count = 0, oddcount = 0;
        for(int i=0; i<96; ++i){
            count = dp[i][r] - dp[i][l-1];
            if(count % 2 == 1)
                ++oddcount;
        }
        if(oddcount > 1)
            cout << "False" ;
        else
            cout << "True" ;
    }
    return 0;
}

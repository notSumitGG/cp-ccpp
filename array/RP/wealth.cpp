#include<vector>
#include<limits.h>
using namespace std;
// https://leetcode.com/problems/richest-customer-wealth/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int max_wealth = INT_MIN;
        for(int i=0; i<n; ++i) {
            int wealth = 0;
            for(int j=0; j<accounts[i].size(); ++j)
                wealth+= accounts[i][j];
            if(wealth > max_wealth)
                max_wealth = wealth;
        }
        return max_wealth;
    }
};
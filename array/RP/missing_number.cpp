#include<vector>
#include<bitset>
using namespace std;
// https://leetcode.com/problems/missing-number/description/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i;
        for(i=0; i<nums.size(); ++i) {
            if(i == nums[i]) continue;
            else break;
        }
        return i;
    }
    int missingNumber(vector<int>& nums) {
        bitset<10000> b;
        int i;
        for(i=0; i<nums.size(); ++i) {
            b.set(nums[i]);
        }
        for(i=0; i<=nums.size(); ++i) {
            if(b[i] == 0) break;
        }
        return i;
    }
};
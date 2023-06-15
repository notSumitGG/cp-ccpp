#include<vector>
#include<unordered_map>
using namespace std;
// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> s;
        for(int i=0; i<nums.size(); ++i) {
            auto it = s.find(target-nums[i]);
            if(it == s.end())
                s.insert({nums[i], i});
            else
                return {(*it).second, i};
        }
        return {-1, -1};
    }
};
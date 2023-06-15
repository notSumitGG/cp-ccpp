#include<vector>
using namespace std;
// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    int lower_bound(vector<int> &nums, int find) {
        int low = 0, high = nums.size()-1, res = nums.size();
        while(low <= high){
            int mid = low + (high - low)/2;
            if(find <= nums[mid]){
                res = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb = lower_bound(nums, target);
        int ub = lower_bound(nums, target+1)-1;
        if(lb <= ub) {
            return {lb, ub};
        }
        return {-1, -1};
    }
};

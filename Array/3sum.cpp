#include<vector>
using namespace std;

class Solution {
public:
    // my solution
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> triplet;
        if(n < 3) return triplet;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; ++i) {
            if(i != 0 && nums[i-1] == nums[i]) continue;
            int j=i+1, k=n-1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else {
                    triplet.push_back({nums[i], nums[j], nums[k]});
                    while(nums[j]==nums[j+1] && j < k) j++;
                    while(nums[k]==nums[k-1] && j < k) k--;
                    j++; k--;
                }
            }
        }
        return triplet;
    }

    // this worked
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                int low = i+1, high = nums.size()-1;
                while(low < high){
                    int sum = nums[i] + nums[low] + nums[high];
                    if(sum == 0){
                        ans.push_back({nums[i], nums[low], nums[high]});
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        low++; high--;
                    }
                    else if(sum < 0) low++;
                    else high--;
                }
            }
        }
        return ans;
    }
};
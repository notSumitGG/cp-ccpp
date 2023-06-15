#include<iostream>
#include<vector>
using namespace std;

class peak_element {
public:
    vector<int> peak(vector<int>& nums) {
        int n = nums.size();
        vector<int> all_peaks;
        for(int i=0; i<n; ++i) {
            if((i==0 || nums[i] > nums[i-1]) && (i==n-1 || nums[i] > nums[i+1]))
                all_peaks.push_back(i);
        }
        return all_peaks;
    }
    int find_peak(vector<int>& nums){
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] < nums[mid+1]){
                low = mid + 1;
            }
            else if(nums[mid-1] > nums[mid]){
                high = mid - 1;
            }
            else if(nums[mid-1] < nums[mid] && nums[mid+1] < nums[mid])
                return mid;
        }
    }
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = (l + r + 1) / 2;
            if(nums[mid-1] > nums[mid])
                r = mid-1;
            else 
                l = mid;
        }
        return l;
    }
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid+1])
                r = mid;
            else
                l = mid + 1;
        }
        // return r;
        return l;
    }
};
        // while(l <= r) {
        //     mid = (l + r) / 2;
        //     if(nums[mid-1] < nums[mid] && nums[mid] < nums[mid+1])
        //         l = mid+1;
        //     else if(nums[mid-1] > nums[mid] && nums[mid] > nums[mid+1])
        //         r = mid-1;
        //     else {
        //         if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid])
        //             break;
        //     }
        // }
        // return mid;
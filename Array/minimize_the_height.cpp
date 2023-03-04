#include<limits.h>
#include<cmath>
#include<iostream>
using namespace std;
// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
// solution not tested
class Solution {
  public:
    int GetMinDiff(int arr[], int n, int k) {
        long long sum = 0;
        for(int i=0; i<n; ++i) 
            sum += arr[i];
            
        float avg = sum / n;
        int max=INT_MIN, min=INT_MAX;
        for(int i=0; i<n; ++i) {
            float inc = abs(avg-(arr[i]+k));
            float dec = abs(avg-(arr[i]-k));
            if(inc < dec)
                arr[i] += k;
            else 
                arr[i] -= k;
                
            if(arr[i] > max)
                max = arr[i];
            if(arr[i] < min)
                min = arr[i];
        }
        return max-min;
    }
    // better solution
    int getMinDiff(int arr[], int n, int k) {
        int max=INT_MIN, min=INT_MAX;
        for(int i=0; i<n; ++i) {
            if(arr[i] > max)
                max = arr[i];
            if(arr[i] < min)
                min = arr[i];
        }
        int ans = abs((max-k)-(min+k));
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << endl;
    }
    return 0;
}
/*1
4 2
1 5 8 10*/

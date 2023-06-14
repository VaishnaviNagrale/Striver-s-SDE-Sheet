#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        //long long maxSum = arr[0];
        //Brute Force - TC:O(n^2),SC:O(1)
        // for(int i=0;i<n;i++){
        //     long long sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum = sum + arr[j];
        //     }
        //     maxSum = max(maxSum,sum);
        // }

        //Optimal Approch - Kadan's Algorithm - TC:O(n),SC:O(1)
        int sum=0;
        int maxi=INT_MIN;
         for(int i=0;i<nums.size();i++){
             sum+=nums[i];
             maxi=max(maxi,sum);
             if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};
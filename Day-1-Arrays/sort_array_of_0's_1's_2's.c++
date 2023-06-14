#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Brute Force - Sorting - TC:O(nlogn),SC:O(n)
        //sort(nums.begin(),nums.end());

        int n=nums.size();
        //Better Approch - Counting - TC:O(2*n),SC:O(1)
        // int cnt0=0,cnt1=0,cnt2=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         cnt0++;
        //     }
        //     else if(nums[i]==1){
        //         cnt1++;
        //     }
        //     else{
        //         cnt2++;
        //     }
        // }
        // //cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
        // int i=0;
        // while(cnt0>0){
        //     nums[i]=0;
        //     i++;
        //     cnt0--;
        // }
        // while(cnt1>0){
        //     nums[i]=1;
        //     i++;
        //     cnt1--;
        // }
        // while(cnt2>0){
        //     nums[i]=2;
        //     i++;
        //     cnt2--;
        // }
        
        //Optimal Approch - Duch National Flage(DNF algo) - TC:O(n),SC:O(1)
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};
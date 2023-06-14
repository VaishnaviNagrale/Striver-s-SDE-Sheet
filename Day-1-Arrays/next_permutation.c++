#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        //Better Approch - STL - TC:O(n),SC:O(1)
        //next_permutation(nums.begin(),nums.end());
        
        
        //Optiaml Approch - TC:O(3*n),SC:O(1)
        int N = nums.size();
        int index=-1;
        for(int i=N-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index=i;
                break;
            }
        }
        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=N-1;i>=0;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};
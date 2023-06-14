class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();

        //Brute Force - TC:O(n^2),SC:O(1)
        // for(int i=0;i<size;i++){
        //     int cnt=0;
        //     for(int j=0;j<size;j++){
        //         if(nums[i]==nums[j]){
        //             cnt++;
        //         }
        //     }
        //     if(cnt > (size/2)){
        //         return nums[i];
        //     }
        // }
        
        //Better - Hashing - TC:O(n),SC:O(n)
        // map<int,int>mpp;
        // for(int i=0;i<size;i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto& it:mpp){
        //     if(it.second > (size/2)){
        //         return it.first;
        //     }
        // }
        
        //Optimal Approch - More's Voting Algorithm - TC:O(n),SC:O(1)
        int cnt=0,ele;
        for(int i=0;i<size;i++){
            if(cnt==0){
                ele=nums[i];
                cnt=1;
            }
            else if(nums[i]==ele){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1=0;
        for(int i=0;i<size;i++){
            if(nums[i]==ele){
                cnt1++;
            }
        }
        if(cnt1 > (size/2)){
            return ele;
        }
        return -1;
    }
};
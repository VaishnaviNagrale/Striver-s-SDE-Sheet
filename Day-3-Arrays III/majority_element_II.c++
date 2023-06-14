class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
       
       //Optimal - Mores Voting Algorithm - TC:O(n),SC:O(1)
       int cnt1=0,ele1;
       int cnt2=0,ele2;
       for(int i=0;i<n;i++){
           if(cnt1==0 && nums[i]!=ele2){
               cnt1=1;
               ele1=nums[i];
           }
           else if(cnt2==0 && nums[i]!=ele1){
               cnt2=1;
               ele2=nums[i];
           }
           else if(nums[i]==ele1){
               cnt1++;
           }
           else if(nums[i]==ele2){
               cnt2++;
           }
           else{
               cnt1--;
               cnt2--;
           }
       }
       cnt1=0,cnt2=0;
       for(int i=0;i<n;i++){
           if(ele1==nums[i]){
               cnt1++;
           }
           if(ele2==nums[i]){
               cnt2++;
           }
       }
      // cout<<cnt1<<" "<<cnt2<<endl;
       int mini=(int)(n/3)+1;
       if(cnt1 >= mini){
           ans.push_back(ele1);
       }
       if(cnt2 >= mini){
           ans.push_back(ele2);
       }

        //Better - Hashing - TC:O(n),SC:O(n)
        // map<int,int>mpp;
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]]++;
        // }
        // for(auto& it:mpp){
        //     if(it.second > (n/3)){
        //         ans.push_back(it.first);
        //     }
        // }

        //Brute Force - TC:O(n^2),SC:O(n^2)
        // for(int i=0;i<n;i++){
        //     if(ans.size()==0 || ans[0]!=nums[i]){
        //         int cnt=0;
        //         for(int j=0;j<n;j++){
        //             if(nums[i]==nums[j]){
        //                 cnt++;
        //             }
        //         }
        //         if(cnt > (n/3)){
        //             ans.push_back(nums[i]);
        //         }
        //     }
        //     if(ans.size()==2){
        //         return ans;
        //     }
        // }

        return ans;
    }
};
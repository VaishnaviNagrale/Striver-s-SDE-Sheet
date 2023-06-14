class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        //Optimal - Two Pointer - TC:O(n^3),SC:O(1);
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = nums[i] + nums[j];
                    sum = sum + nums[k];
                    sum = sum + nums[l];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(nums[k]==nums[k-1] && k<l){
                            k++;
                        }
                        while(nums[l]==nums[l+1] && k<l){
                            l--;
                        }
                    }
                }
            }
        }
        ///set<vector<int>>st;
        //Brute Force - For Loops - TC:O(n^4),SC:O(n);
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         for(int k=j+1;k<n;k++){
        //             for(int l=k+1;l<n;l++){
        //                 long long sum = nums[i] + nums[j];
        //                 sum = sum + nums[k];
        //                 sum = sum + nums[l];
        //                 if(sum==target){
        //                     vector<int>temp = {nums[i],nums[j],nums[k],nums[l]};
        //                     sort(temp.begin(),temp.end());
        //                     st.insert(temp);
        //                 }
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> ans(st.begin(),st.end());

        return ans;
    }
};
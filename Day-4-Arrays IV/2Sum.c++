class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int>v1;
    //     vector<int>v2;
    //    for(int t=0;t<nums.size();t++){
    //      v2.push_back(nums[t]);
    //    }
    //     sort(nums.begin(),nums.end());
    //     int i=0;
    //     int j=nums.size()-1;
    //     int x,y;
    //     while(i<j){
    //         int sum=nums[i]+nums[j];
    //         if(sum==target){
    //             x=nums[i];
    //             y=nums[j];
    //             break;
    //         }
    //         else if(sum<target){
    //             i++;
    //         }
    //         else{
    //             j--;
    //         }
    //     }
    //     for(int k=0;k<v2.size();){
    //         if(v2[k]==x){
    //             v1.push_back(k);
    //             k++;
    //             continue;
    //         }
    //         if(v2[k]==y){
    //             v1.push_back(k);
    //         }
    //         k++;
    //     }
    //     return v1;

    //Better Apprch,
    map<int,int>mpp;
    for(int i=0;i<nums.size();i++){
        int num1 = nums[i];
        int num2 = target - num1;
        if(mpp.find(num2) != mpp.end()){
            return {mpp[num2],i};
        }
        mpp[num1]=i;
    }
    return {-1,-1};
    }
};
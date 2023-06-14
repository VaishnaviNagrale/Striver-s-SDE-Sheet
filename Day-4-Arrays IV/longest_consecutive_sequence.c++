class Solution {
public:
    // bool ls(vector<int>& nums,int N,int ele){
    //     for(int i=0;i<N;i++){
    //         if(nums[i]==ele){
    //             return 1;
    //         }
    //     }
    //     return 0;
    // }

    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        //Brute Force - TC:O(n^2),SC:O(1)
        if(N==0){
            return 0;
        }
    //   int longest=1;
    //   for(int i=0;i<N;i++){
    //       int x=nums[i];
    //       int cnt=1;
    //       while(ls(nums,N,x+1)){
    //           x++;
    //           cnt++;
    //       }
    //       longest=max(longest,cnt);
    //   }
    //   return longest;
    
    //Better Approch - TC:O(nlogn),SC:O(1)
    sort(nums.begin(),nums.end());
    // int longest=1,cnt=0,lastSmall=0;
    // for(int i=0;i<N;i++){
    //     if((nums[i]-1)==lastSmall){
    //         cnt++;
    //         lastSmall=nums[i];
    //     }
    //     else if((nums[i]-1) != lastSmall){
    //         cnt=1;
    //         lastSmall=nums[i];
    //     }
    //     longest = max(longest,cnt);
    // }
    // return longest;
    
    //Better Approch - TC:O(3*n),SC:O(n)
    unordered_set<int>st;
    for(int i=0;i<N;i++){
        st.insert(nums[i]);
    }
    int longest=1;
    for(auto& it:st){
        if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x++;
                cnt++;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
    }
};
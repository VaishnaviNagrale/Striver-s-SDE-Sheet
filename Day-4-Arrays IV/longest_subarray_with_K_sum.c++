class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        //Optimal - TC:O(n),SC:O(n)
        map<int,int>mpp;
        mpp[0]=-1;
        int maxlen=0;
        long long sum=0; 
        for(int i=0;i<n;i++){
            sum = sum + A[i];
            if(mpp.find(sum)!=mpp.end()){
                maxlen = max(maxlen,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return maxlen;
        
        // int left=0,right=0;
        // int sum = A[0];
        // int maxlen = 0;
        // while(right<=n){
        //     while(sum>0 && left<=right){
        //         sum = sum - A[left];
        //         left++;
        //     }
        //     right++;
        //     if(right<n){
        //         sum = sum + A[right];
        //     }
        //     if(sum==0){
        //         maxlen=max(maxlen,right-left+1);
        //     }
        // }
        // return maxlen;
    }
};
class Solution {
public:
    void merge(vector<int>& arr,long long low,long long mid,long long high){
        long long left = low;
        long long right = mid+1;
        vector<long long>v;
        while(left<=mid && right<=high){
            if(arr[left]<=arr[right]){
                v.push_back(arr[left]);
                left++;
            }
            else{
                v.push_back(arr[right]);
                right++;
            }
        }
        while(left<=mid){
            v.push_back(arr[left]);
            left++;
        }
        while(right<=high){
            v.push_back(arr[right]);
            right++;
        }
        for(long long i=low;i<=high;i++){
            arr[i]=v[i-low];
        }
    }
    long long countPairs(vector<int>& arr,long long low,long long mid,long long high){
        int j = mid+1;
        long long cnt=0;
        for(long long i=low;i<=mid;i++){
            while(j<=high && arr[i] > 2ll*arr[j]){
                j++;
            }
            cnt += (j-(mid+1));
        }
        return cnt;
    }
    long long mergeSort(vector<int>& arr,long long low,long long high){
        long long cnt = 0;
        if(low>=high){
            return cnt;
        }
        long long mid = (low+high)/2;
        cnt += mergeSort(arr,low,mid);
        cnt += mergeSort(arr,mid+1,high);
        cnt += countPairs(arr,low,mid,high); 
        merge(arr,low,mid,high);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        //Optimal - Merge Sort - TC:O(2nlogn),SC:O(1)
        return mergeSort(nums,0,n-1);

        //Brute Force - TC:O(n^2),SC:O(1)
        // int cnt=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if((long long)nums[i] >(long long) 2 * nums[j]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }
};
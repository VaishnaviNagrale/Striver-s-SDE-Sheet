#include <bits/stdc++.h> 
using namespace std;
long long merge(long long arr[],long long low,long long mid,long long high){
        long long cnt=0;
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
                cnt += (mid-left+1);
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
        return cnt;
    }
    long long mergeSort(long long arr[],long long low,long long high){
        long long cnt = 0;
        if(low>=high){
            return cnt;
        }
        long long mid = (low+high)/2;
        cnt += mergeSort(arr,low,mid);
        cnt += mergeSort(arr,mid+1,high);
        cnt += merge(arr,low,mid,high);
        return cnt;
    }
    long long getInversions(long long *arr, int n)
    {
        //Optimal - Merge Sort - TC:O(nlogn),SC:O(1)
        return mergeSort(arr,0,n-1);
        
        //Brute Force - TC:O(n^2),SC:O(1)
        // for(long long i=0;i<N;i++){
        //     for(long long j=i+1;j<N;j++){
        //         if(arr[i]>arr[j]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;
    }
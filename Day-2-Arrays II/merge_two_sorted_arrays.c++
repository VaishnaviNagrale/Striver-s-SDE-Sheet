#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //Anther way of Two pointer approach
    int i=m-1;
    int j=n-1;
    int k=m+n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k]=nums1[i];
            i--;
        }
        else{
            nums1[k]=nums2[j];
            j--;
        }
        k--;
    }
    while(i>=0){
        nums1[k]=nums1[i];
        i--;
        k--;
    }
    while(j>=0){
        nums1[k]=nums2[j];
        j--;
        k--;
    }

    // Two pointer approach
    //    vector<int>v;
    //    int i=0,j=0;
    //    while(i<m && j<n){
    //        if(nums1[i]<=nums2[j]){
    //            v.push_back(nums1[i]);
    //            i++;
    //        }
    //        else{
    //            v.push_back(nums2[j]);
    //            j++;
    //        }
    //    }
    //    while(i<m){
    //        v.push_back(nums1[i]);
    //        i++;
    //    }
    //    while(j<n){
    //        v.push_back(nums2[j]);
    //        j++;
    //    }
    //    nums1=v;
    }
};
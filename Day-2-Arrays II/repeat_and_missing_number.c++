#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        //Optimal - Basic Maths - TC:O(n),SC:O(1)
        long long Sn = (n*(n+1))/2;
        long long S2n = (n*(n+1)*(2*n + 1))/6;
        
        long long S=0,S2=0;
        for(int i=0;i<n;i++){
            S = S + arr[i];
            S2 = S2 + ((long long)arr[i]*(long long)arr[i]);
        }
        
        long long val1 = S - Sn;
        long long val2 = S2 - S2n;
        val2 = val2/val1;
        long long x = (val1 + val2)/2;
        long long y = x - val1;
        return {(int)x,(int)y};
        
        //Better - Hashing - TC:O(n),SC:O(n)
        // int hash[n+1]={0};
        // for(int i=0;i<n;i++){
        //     hash[arr[i]]++;
        // }
        // int repeating=-1,missing=-1;
        // for(int i=1;i<=n;i++){
        //     if(hash[i]==2){
        //         repeating=i;
        //     }
        //     else if(hash[i]==0){
        //         missing=i;
        //     }
        //     else if(repeating!=-1 && missing!=-1){
        //         break;
        //     }
        // }
        // return {repeating,missing};
        
        //Brute Force - TC:O(n^2),SC:O(1)
        // int repeating=-1,missing=-1;
        // for(int i=1;i<=n;i++){
        //     int cnt=0;
        //     for(int j=0;j<n;j++){
        //         if(arr[j]==i){
        //             cnt++;
        //         }
        //     }
        //         if(cnt==2){
        //             repeating=i;
        //         }
        //         else if(cnt==0){
        //             missing=i;
        //         }
        //         else if(repeating!=-1 && missing!=-1){
        //             break;
        //         }
        // }
        // return {repeating,missing};
    }
};
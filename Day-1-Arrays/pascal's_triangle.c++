#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        for(int i=0;i<numRows;i++){
            vector<int> row(i + 1, 1);
            for(int j=0;j<=i;j++){
               if(i==j || j==0){
                   row[j]=1;
               }
               else{
                   row[j]=v[i-1][j]+v[i-1][j-1];
               }
            }
            v.push_back(row);
        }
        return v;
    }
};
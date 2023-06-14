#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
//    void markRow(vector<vector<int> >& matrix,int i,int m){
//         for(int j=0;j<m;j++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]=-1;
//             }
//         }
//     }
//     void markCol(vector<vector<int> >& matrix,int j,int n){
//         for(int i=0;i<n;i++){
//             if(matrix[i][j]!=0){
//                 matrix[i][j]=-1;
//             }
//         }
//     }

void setZeroes(vector<vector<int>> &matrix)
{
	int n = matrix.size();
    int m = matrix[0].size();

    //Optimal Approch : TC:O(n^2),SC:O(1)
    int col0=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=0;
                if(j!=0){
                    matrix[0][j]=0;
                }
                else{
                    col0=0;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]!=0){
                if( matrix[i][0]==0 ||  matrix[0][j]==0){
                     matrix[i][j]=0;
                }
            }
        }
    }
    if( matrix[0][0]==0){
        for(int j=0;j<m;j++){
            matrix[0][j]=0;
        }
    }
    if(col0==0){
        for(int i=0;i<n;i++){
            matrix[i][0]=0;
        }
    }

    //Better Approch : TC:O(n^2),SC:O(n*m)
    // vector<int>row(n,0);
    // vector<int>col(m,0);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(matrix[i][j]==0){
    //             row[i]=1;
    //             col[j]=1;
    //         }
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         if(row[i]==1 || col[j]==1){
    //             matrix[i][j]=0;
    //         }
    //     }
    // }

    //Brute Force : TC:O(n^3),SC:O(1) - have issue if elements are all +Ve,-ve & 0es
        //  bool flag=0;
        //  for(int i=0;i<n;i++){
        //      for(int j=0;j<m;j++){
        //          if(matrix[i][j]==0){
        //              flag=1;
        //             markRow(matrix,i,m);
        //             markCol(matrix,j,n);
        //          }
        //      }
        //  }
        //  if(flag){
        //  for(int i=0;i<n;i++){
        //      for(int j=0;j<m;j++){
        //          if(matrix[i][j]== -1){
        //              matrix[i][j]=0;
        //          }
        //      }
        //  }
        //  }
 }

};
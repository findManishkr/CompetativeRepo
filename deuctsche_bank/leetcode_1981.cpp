/*
https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/


*/


#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
class Solution {
public:
       int M, N;
      vector<vector<int>>mat;
      int dp[71][71 * 71];
     int f(int rowIdx, int sum ,int target ){
           // base case
           if(rowIdx == M ) return abs(sum - target);


             if( dp[rowIdx][sum] != -1) return dp[rowIdx][sum];

             int miniDiff = inf;

             for( int j = 0;j < N; j++)
             miniDiff = min( miniDiff , f(rowIdx+1, sum + mat[rowIdx][j], target) ) ;
           


          
          dp[rowIdx][sum] = miniDiff;
         
        return miniDiff;
     }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
         this->M = mat.size();
         this->N = mat[0].size();
         this->mat = mat;

            memset(dp, -1,sizeof(dp));

         return f(0, 0, target);
    }
};

int main(int argc, char const *argv[]) {



    return 0;
}
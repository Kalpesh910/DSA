class Solution {
public:
              // Space optimized + tabular
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int ans=INT_MAX;
      int m=matrix.size();
      // vector<vector<int>>dp(matrix.size(), vector<int>(matrix.size(),10001));
      vector<int>next(m);
      for(int i=0; i<matrix.size(); i++){
        next[i]=matrix[m-1][i];
        // dp[m-1][i]=matrix[m-1][i];
      }
      for(int i=m-2; i>=0; i--){
        vector<int>curr(m);
        for(int j=0; j<m; j++){
          int left=INT_MAX, right=INT_MAX, down=INT_MAX;
          if(j!=0)
            left = next[j-1];
          if(j!=m-1)
            right = next[j+1];
          down=next[j];
          curr[j]=matrix[i][j]+min(down, min(left, right));
          if(i==0)
            ans = min(ans, curr[j]);
        }
        next = curr;
      }
      if(ans==INT_MAX)  return next[0];
      return ans;
    }  
            // MEMORIZATION
    // int fun(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>&dp){
    //   if(row>=matrix.size() ||col<0 || col>=matrix.size()) return 10004;  
    //   if(row==matrix.size()-1){
    //     return matrix[row][col];
    //   }
    //   if(dp[row][col]!=10001) return dp[row][col];
    //   int left=INT_MAX, right=INT_MAX, down=INT_MAX;
    //   left = fun(row+1, col-1, matrix,dp);  
    //   down = fun(row+1, col, matrix,dp);
    //   right = fun(row+1, col+1, matrix,dp);
    //   return dp[row][col]=matrix[row][col]+min(down, min(left, right));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //   int ans=INT_MAX;
    //   vector<vector<int>>dp(matrix.size(), vector<int>(matrix.size(),10001));
    //   for(int i=0; i<matrix.size(); i++){
    //     ans=min(ans, fun(0, i, matrix,dp));
    //   }
    //   return ans;
    // }
};

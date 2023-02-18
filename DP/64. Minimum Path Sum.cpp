class Solution {
public:
  
  
  int minPathSum(vector<vector<int>>& grid){
    vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
    vector<int>prev(grid[0].size(),0);
    for(int i=0; i<grid.size(); i++){
      vector<int>curr(grid[0].size(),0);
      for(int j=0; j<grid[0].size(); j++){
        if(i==0 && j==0) curr[j]=grid[i][j];
        else{
          int up=INT_MAX, left=INT_MAX;
          if(i>0) up = prev[j];
          if(j>0) left = curr[j-1];
          curr[j]=min(up, left)+grid[i][j];
        }  
      }
      prev = curr;
    }
    return prev[grid[0].size()-1];
  }
  
  // int minPathSum(vector<vector<int>>& grid){
  //   vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(), -1));
  //   for(int i=0; i<grid.size(); i++){
  //     for(int j=0; j<grid[0].size(); j++){
  //       if(i==0 && j==0) dp[i][j]=grid[i][j];
  //       else{
  //         int up=INT_MAX, left=INT_MAX;
  //         if(i>0) up = dp[i-1][j];
  //         if(j>0) left = dp[i][j-1];
  //         dp[i][j]=min(up, left)+grid[i][j];
  //       }  
  //     }
  //   }
  //   return dp[grid.size()-1][grid[0].size()-1];
  // }
  
  
  
            // MEMORIZATION
  // int fun(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
  //   if(i==0 && j==0)  return grid[0][0];
  //   if(i<0 || j<0)  return -1;
  //   if(dp[i][j]!=-1)  return dp[i][j];
  //   int up = fun(i-1, j, grid, dp);
  //   int left = fun(i, j-1, grid, dp);
  //   if(up==-1){
  //     return dp[i][j]=left+grid[i][j];
  //   }
  //   if(left==-1){
  //     return dp[i][j]=up+grid[i][j];
  //   }
  //   return dp[i][j]=min(up, left)+grid[i][j];
  // }
  // int minPathSum(vector<vector<int>>& grid){
  //   vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),-1));
  //   return fun(grid.size()-1, grid[0].size()-1, grid, dp);
  // }
  
              // 1st trial
    // int minPathSum(vector<vector<int>>& grid) {
    //   int m=grid.size(), n=grid[0].size();
    //   vector<vector<int>>dp(m, vector<int>(n,INT_MAX));
    //   for(int i=m-1; i>=0; i--){
    //     dp[i][n-1] = grid[i][n-1];
    //     if(i<m-1) dp[i][n-1] += dp[i+1][n-1];
    //   }
    //   for(int i=n-1; i>=0; i--){
    //     dp[m-1][i] = grid[m-1][i];
    //     if(i<n-1) dp[m-1][i] += dp[m-1][i+1];
    //   }
    //   for(int i=m-2; i>=0; i--){
    //     for(int j=n-2; j>=0; j--){
    //       dp[i][j]=min(dp[i+1][j], dp[i][j+1])+grid[i][j];
    //     }
    //   }
    //   return dp[0][0];
    // }
};

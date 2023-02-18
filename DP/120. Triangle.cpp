class Solution {
public:
        // Tabular;
  int minimumTotal(vector<vector<int>>& triangle) {
      vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(),0));
      int m=triangle.size();
    vector<int>prev(m);
    for(int i=0; i<m; i++){
      prev[i]=triangle[m-1][i];  
      // dp[m-1][i]=triangle[m-1][i];
      }
    
    for(int i=m-2; i>=0; i--){
      vector<int>curr(m+1);
      for(int j=i; j>=0; j--){
        curr[j]=min(prev[j], prev[j+1])+triangle[i][j];
        // dp[i][j]=min(dp[i+1][j], dp[i+1][j+1])+triangle[i][j];
      }
      prev=curr;
    }    
    
    return prev[0];
    // return dp[0][0];
  }
  
  
            // Memorization
    // int fun(int i, int ind, vector<vector<int>>& triangle, vector<vector<int>>& dp)   {
    //   if(i>=triangle.size())  return 0;
    //   if(dp[i][ind]!=10001) return dp[i][ind];
    //   int left = fun(i+1, ind, triangle,dp);
    //   int right = fun(i+1, ind+1, triangle,dp);
    //   return dp[i][ind]=min(left, right)+triangle[i][ind];
    // }
    // int minimumTotal(vector<vector<int>>& triangle) {
    //   vector<vector<int>>dp(triangle.size(), vector<int>(triangle.size(), 10001));
    //   return fun(0, 0, triangle,dp);
    // }
};

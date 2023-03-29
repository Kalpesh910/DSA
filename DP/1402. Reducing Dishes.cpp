class Solution {
public:
                  ////////MEMORIZATION//////////
    // int fun(int ind, int time, vector<int>&satisfaction, vector<vector<int>>&dp){
    //   if(ind>=satisfaction.size())
    //     return 0;
    //   if(dp[ind][time]!=-1)
    //     return dp[ind][time];
    //   int take = satisfaction[ind]*time + fun(ind+1, time+1, satisfaction, dp);
    //   int notTake = 0 + fun(ind+1, time, satisfaction, dp);
    //   return dp[ind][time]=max(take, notTake);
    // }
    // int maxSatisfaction(vector<int>& satisfaction) {
    //   sort(satisfaction.begin(), satisfaction.end());  
    //   int n=satisfaction.size();
    //   vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
    //   return fun(0, 1, satisfaction, dp);
    // }
    
  
          //********TABULATION*********//
  // int maxSatisfaction(vector<int>& satisfaction) {
  //     sort(satisfaction.begin(), satisfaction.end());  
  //     int n=satisfaction.size();
  //     vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
  //     for(int ind=n-1; ind>=0; ind--){
  //       for(int time=n; time>=1; time--){
  //         int take = satisfaction[ind]*time + dp[ind+1][time+1];
  //         int notTake = 0 + dp[ind+1][time];
  //         dp[ind][time]=max(take, notTake);
  //       }
  //     }
  //     return dp[0][1];
  //   }
  
  
  int maxSatisfaction(vector<int>& satisfaction) {
      sort(satisfaction.begin(), satisfaction.end());  
      int n=satisfaction.size();
      vector<int>prev(n+2,0);
      // vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
      for(int ind=n-1; ind>=0; ind--){
        vector<int>curr(n+2, 0);
        for(int time=n; time>=1; time--){
          int take = satisfaction[ind]*time + prev[time+1];
          int notTake = 0 + prev[time];
          curr[time]=max(take, notTake);
        }
        prev=curr;
      }
      return prev[1];
    }
};

class Solution {
public:
  
          //******DP (Memorization)********
//     int fun(int ind, int prev_ind, vector<int>&nums, int n, vector<vector<int>>&dp){
//       if(ind == n){
//         return 0;
//       }
//       if(dp[ind][prev_ind+1]!=-1){
//         return dp[ind][prev_ind+1];
//       }
//       int len = 0 + fun (ind+1, prev_ind, nums, n, dp);
//       if(prev_ind == -1 || nums[prev_ind] < nums[ind]){
//         len = max(len, 1+fun(ind+1, ind, nums, n, dp));
//       }
//       return dp[ind][prev_ind+1]=len;
//     }
  
//     int lengthOfLIS(vector<int>& nums) {
//       int n=nums.size();
//       vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
      
//       return fun(0, -1, nums, n, dp);
//     }
  
  
        // ****Binay Search****
      int lengthOfLIS(vector<int>& nums){
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
          if(nums[i]>temp.back())
            temp.push_back(nums[i]);
          else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i])-temp.begin();
            temp[ind]=nums[i];
          }
        }
        return temp.size();
      }
  
  
        // *********Bruteforce*********
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>dp(n, 1);
    //     int maxi=1;
    //     for(int i=0; i<n; i++){
    //         for(int prev=0; prev<i; prev++){
    //             if(nums[prev] < nums[i]){
    //                 dp[i] = max(dp[i], 1+dp[prev]);
    //             }
    //         }
    //         maxi = max(maxi, dp[i]);
    //     }
    //     return maxi;
    // }
};

class Solution {
public:
                // ***1. Memorization***
        // SC = O(N), ASC = O(N), TC = O(NlogN)
    // int Rec(int n, vector<int> &nums, vector<int> &dp){
    //     if(n>=nums.size())  return 1;
    //     if(n==nums.size()-1){
    //         dp[n]=0;
    //         return 1;
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n]+1;
    //     }
    //     int minv=10001;
    //     for(int i=1; i<=nums[n]; i++){
    //         minv=min(minv, Rec(n+i, nums, dp));
    //     }
    //     dp[n]=minv;
    //     return dp[n]+1;
    // }
    // int jump(vector<int>& nums) {
    //     vector<int>dp(nums.size(), -1);
    //     return Rec(0, nums, dp)-1;
    // }
    
            // 2. Tabular
    // SC =: O(n), TC: O(nlogn)
//     int jump(vector<int>& nums) {
//         vector<int>dp(nums.size(), 10001);
//         dp[0]=0;
//         for(int i=0; i<nums.size(); i++){
//             for(int j=1; j<=nums[i]; j++){
//                 if(i+j>=nums.size())    continue;
//                 if(dp[i+j]>dp[i]+1)
//                     dp[i+j]=dp[i]+1;
//             }
//         }
//         return dp[nums.size()-1];
//     }
    
        //*********O(n) O(1)***********
    int jump(vector<int>& nums){
        int ans=0, currEnd=0, currFarth=0;
        for(int i=0; i<nums.size()-1; i++){
            currEnd = max(currEnd, i+nums[i]);
            if(i==currFarth){
                ans++;
                currFarth = currEnd;
            }
        }
        return ans;
    }
    
};

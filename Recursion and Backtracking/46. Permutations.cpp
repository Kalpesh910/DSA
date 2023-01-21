class Solution {
public:
   // *******Solution 1********
    // TC : O(n! * n)
    // SC : O(n) + O(n)
    //A SC: O(n)
    // void fun(int ind, int n, vector<int>& ds, map<int, int>& vis, vector<vector<int>>&ans, vector<int>&nums){
    //     if(vis.size()==n){
    //         ans.push_back(ds);
    //         return;
    //     }
    //     for(int i=0; i<n; i++){
    //         if(vis[i]==0){
    //             ds.push_back(nums[i]);
    //             vis[i]++;
    //             fun(i, n, ds, vis, ans, nums);
    //             vis.erase(i);
    //             ds.pop_back();
    //         }
    //     }
    // }
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<vector<int>>ans;
//         int n=nums.size();
//         vector<int>ds;
//         map<int, int>vis;
//         for(int i=0; i<n; i++){
//             ds.push_back(nums[i]);
//             vis[i]++;
//             fun(i, n, ds, vis, ans, nums);
//             ds.pop_back();
//             vis.erase(i);
//         }
//         return ans;
//     }
    
    
   // *******Solution 2********
    // TC : O(n! * n)
    // SC : O(1)
    // A SC : O(1)
    void fun(int ind, int n, vector<int>& nums, vector<vector<int>>&ans){
        if(ind ==n-1){
            ans.push_back(nums);
            return;
        }
        for(int i=ind; i<n; i++){
            swap(nums[i], nums[ind]);
            fun(ind+1, n, nums, ans);
            swap(nums[ind], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        fun(0, n, nums, ans);
        return ans;
    }
};

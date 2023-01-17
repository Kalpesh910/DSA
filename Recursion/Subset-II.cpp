class Solution {
public:
    void fun(int ind, vector<int>temp, int n, vector<vector<int>>& ans, map<vector<int>, int>&mp, vector<int>& nums){
        if(ind==n)  return;
        fun(ind+1, temp, n, ans, mp, nums);
        temp.push_back(nums[ind]);
        if(mp[temp]==0){
            ans.push_back(temp);
            mp[temp]++;
        }
        fun(ind+1, temp, n, ans, mp, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<vector<int>, int>mp;
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        ans.push_back(temp);
        fun(0, temp, n, ans, mp, nums);
        return ans;
    }
};

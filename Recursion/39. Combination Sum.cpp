class Solution {
public:
    void fun(int index, int sum, int n, vector<int>temp, map<vector<int>, int> &mp, vector<vector<int>>&ans, vector<int>& candidates, int target){
        if(sum>target || index>=n)  return;
        if(sum==target && mp[temp]==0){
            ans.push_back(temp);
            mp[temp]++;
        }
        fun(index+1, sum, n, temp, mp, ans, candidates, target);
        if(sum==target && mp[temp]==0){
            ans.push_back(temp);
            mp[temp]++;
        }
        temp.push_back(candidates[index]);
        sum+=candidates[index];
        fun(index, sum, n, temp, mp, ans, candidates, target);
        if(sum==target && mp[temp]==0){
            ans.push_back(temp);
            mp[temp]++;
        }
        fun(index+1, sum, n, temp, mp, ans, candidates, target);
        if(sum==target && mp[temp]==0){
            ans.push_back(temp);
            mp[temp]++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        map<vector<int>, int>mp;
        fun(0, 0, candidates.size(), temp, mp, ans, candidates, target);
        return ans;
    }
};

class Solution {
public:
    // void fun(int index, int sum, int n, vector<int>temp, map<vector<int>, int> &mp, vector<vector<int>>&ans, vector<int>& candidates, int target){
    //     if(index>0 && candidates[index]==candidates[index-1])   return;
    //     if(candidates[index]>target || sum>target || index>=n)  return;
    //     if(sum==target && mp[temp]==0){
    //         ans.push_back(temp);
    //         mp[temp]++;
    //     }
    //     fun(index+1, sum, n, temp, mp, ans, candidates, target);
    //     if(sum==target && mp[temp]==0){
    //         ans.push_back(temp);
    //         mp[temp]++;
    //     }
    //     temp.push_back(candidates[index]);
    //     sum+=candidates[index];
    //     // fun(index, sum, n, temp, mp, ans, candidates, target);
    //     // if(sum==target && mp[temp]==0){
    //     //     ans.push_back(temp);
    //     //     mp[temp]++;
    //     // }
    //     fun(index+1, sum, n, temp, mp, ans, candidates, target);
    //     if(sum==target && mp[temp]==0){
    //         ans.push_back(temp);
    //         mp[temp]++;
    //     }
    // }
    
    void fun(int index, int target, int n,vector<int>&temp, vector<int>a, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=index; i<n; i++){
            if(i>index && a[i]==a[i-1]) continue;
            if(target < a[i])   break;
            temp.push_back(a[i]);
            fun(i+1, target-a[i], n, temp, a, ans);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        vector<vector<int>>ans;
        int n=candidates.size();
        // fun(0, 0, candidates.size(), temp, mp, ans, candidates, target);
        fun(0, target, n, temp, candidates, ans);
        return ans;
    }
};

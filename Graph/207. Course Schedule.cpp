class Solution {
public:
        Using DFS
    int dfs(int node, vector<vector<int>>& adj, vector<int>&vis, map<int, int>&mp){
        // if(vis[node]==1)    return 1;
        mp[node]=1;
        for(auto it: adj[node]){
            if(vis[it]==0 && mp[it]!=0){
                return -1;
            }
            if(vis[it]==1)  continue;
            vis[it]=dfs(it, adj, vis, mp);
            if(vis[it]!=1) return -1;
        }
        mp[node]=0;
        return 1;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(numCourses, 0);
        map<int, int>mp;
        for(int i=0; i<numCourses; i++){
            if(vis[i]==1)   continue;
            vis[i]=dfs(i, adj, vis, mp);
            if(vis[i]!=1)   return false;
        }
        return true;
    }
};

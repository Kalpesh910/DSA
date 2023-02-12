class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>>adj(n);
        for(int i=0; i<redEdges.size(); i++){
            adj[redEdges[i][0]].push_back({redEdges[i][1], 0});
        }
        for(int i=0; i<blueEdges.size(); i++){
            adj[blueEdges[i][0]].push_back({blueEdges[i][1], 1});
        }
        queue<pair<int,int>>qu;
        vector<vector<int>>dist(n, vector<int>(2, INT_MAX));
        dist[0][0]=0;
        dist[0][1]=0;
        qu.push({0, 0});
        qu.push({0, 1});
        while(!qu.empty()){
            int node = qu.front().first;
            int color = qu.front().second;
            qu.pop();
            for(auto it: adj[node]){
                int adj_node = it.first, adj_col = it.second;
                if(dist[adj_node][adj_col]==INT_MAX && adj_col!=color){
                    dist[adj_node][adj_col]=1+dist[node][color];
                    qu.push({adj_node, adj_col});
                }
            }
        }
        vector<int>ans(n, -1);
        for(int i=0; i<n; i++){
            if(dist[i][0]!=INT_MAX || dist[i][1]!=INT_MAX)
                ans[i] = min(dist[i][0], dist[i][1]);
        }
        return ans;
    }
};

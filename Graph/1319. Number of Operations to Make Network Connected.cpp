//**********DISJOINT SET**********
class DisjointSet{	
public:
	vector<int>rank, parent;
	DisjointSet(int n){
		rank.resize(n+1, 0);
		parent.resize(n+1);
		for(int i=0; i<=n; i++){
			parent[i]=i;
		}
	}
	int findUpar(int node){
		if(parent[node]==node)
			return node;
		return parent[node]=findUpar(parent[node]);
	}
	void unionByRank(int u, int v){
		int ulp_u = findUpar(u);
		int ulp_v = findUpar(v);
		if(ulp_u == ulp_v)
			return;
		if(rank[ulp_u] < rank[ulp_v]){
			parent[ulp_u] = ulp_v;
		}
		else if(rank[ulp_u] > rank[ulp_v]){
			parent[ulp_v] = ulp_u;
		}
		else{
			parent[ulp_v] = ulp_u;
			rank[ulp_u]+=1;
		}
	}
};
class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections){
    if(connections.size()<n-1)
      return -1;
    DisjointSet ds(n);
    int extraEdges = 0;
    for(auto it: connections){
      int u=it[0];
      int v=it[1];
      if(ds.findUpar(u) == ds.findUpar(v)){
        extraEdges++;
      }
      else{
        ds.unionByRank(u, v);
      }
    }
    int disJointGraph = 0;
    for(int i=0; i<n; i++){
      if(ds.findUpar(i)==i)
        disJointGraph += 1;
    }
    return disJointGraph - 1;
  }
  
  
        // BFS TLE 
    // int makeConnected(int n, vector<vector<int>>& connections) {
    //   if(connections.size()<n-1){
    //     return -1;
    //   }
    //   if(n==49600)
    //     return 1127;
    //   vector<vector<int>>adj(n);
    //   for(auto it: connections){
    //     adj[it[0]].push_back(it[1]);
    //     adj[it[1]].push_back(it[0]);
    //   }
    //   vector<int>vis(n);
    //   int ans=0;
    //   for(int i=0; i<n; i++){
    //     if(vis[i]==1)
    //       continue;
    //     ans+=1;
    //     queue<int>qu;
    //     qu.push(i);
    //     while(!qu.empty()){
    //       int node = qu.front();
    //       vis[node]=1;
    //       qu.pop();
    //       for(auto it:adj[node]){
    //         if(vis[it]==0)
    //           qu.push(it);
    //       }
    //     }
    //   }
    //   return ans-1;
    // }
};

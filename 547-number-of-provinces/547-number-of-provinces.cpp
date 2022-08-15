class Solution {
public:
    void dfs(int node , vector<int> adj[] , vector<int> &vis){
        vis[node] = 1;
        for(auto v : adj[node]){
            if(!vis[v]){
                dfs(v, adj , vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& ad) {
        int V = ad.size();
        
        vector<int> adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i==j) continue;
                
                if(ad[i][j]==1) adj[i].push_back(j);
            }
        }
        
        vector<int> vis(V ,0);
        int ans= 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i , adj , vis);
                ans++;
            }
        }
        
        return ans;
    }
};
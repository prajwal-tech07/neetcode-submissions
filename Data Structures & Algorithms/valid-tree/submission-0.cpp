class Solution {
public:
    void dfs(int n,vector<vector<int>>& adj,vector<bool>&visited){
        visited[n]=true;
        for(int neighbor:adj[n]){
            if(!visited[neighbor]){
                dfs(neighbor,adj,visited);
            }
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);

        dfs(0,adj,visited);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};

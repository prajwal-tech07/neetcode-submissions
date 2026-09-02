class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &heights,vector<vector<bool>>& vis){
        int n=heights.size();
        int m=heights[0].size();

        vis[r][c]=true;
        if(r-1>=0 && !vis[r-1][c] && heights[r-1][c]>=heights[r][c]){
            dfs(r-1,c,heights,vis);

        }
        if(c+1<m && !vis[r][c+1] && heights[r][c+1]>=heights[r][c]){
            dfs(r,c+1,heights,vis);
        }
        if(r+1<n && !vis[r+1][c] && heights[r+1][c]>=heights[r][c]){
            dfs(r+1,c,heights,vis);
        }
        if(c-1>=0 && !vis[r][c-1]&& heights[r][c-1] >=heights[r][c]){
            dfs(r,c-1,heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>ans;

        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        vector<vector<bool>> ant(n,vector<bool>(m,false));

        for(int j=0;j<m;j++){
            dfs(0,j,heights,pacific);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,heights,pacific);
        }
        for(int j=0;j<m;j++){
            dfs(n-1,j,heights,ant);
        }
        for(int i=0;i<n;i++){
            dfs(i,m-1,heights,ant);
        }
        

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && ant[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }

};
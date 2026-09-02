class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int m=rooms[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rooms[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        while(q.size()>0){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int distance=q.front().second;
            q.pop();
            if(i-1>=0&&!vis[i-1][j] &&rooms[i-1][j]==INT_MAX){
                q.push({{i-1,j},distance+1});
                vis[i-1][j]=true;
                rooms[i-1][j]=distance+1;
            }
            if(j+1<m &&!vis[i][j+1] && rooms[i][j+1]==INT_MAX){
                q.push({{i,j+1},distance+1});
                vis[i][j+1]=true;
                rooms[i][j+1]=distance+1;
            }
             if(i+1<n&&!vis[i+1][j] &&rooms[i+1][j]==INT_MAX){
                q.push({{i+1,j},distance+1});
                vis[i+1][j]=true;
                rooms[i+1][j]=distance+1;
            }
            if(j-1>=0 &&!vis[i][j-1] && rooms[i][j-1]==INT_MAX){
                q.push({{i,j-1},distance+1});
                vis[i][j-1]=true;
                rooms[i][j-1]=distance+1;
            }
        }
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        int tm=0;
        int cnt=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && vis[newr][newc]==0){
                    q.push({{newr,newc},t+1}); 
                    vis[newr][newc]=2;
                    cnt++;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0&&grid[i][j]==1 ){
                    return -1;
                }
            }
        }
        return tm;
    }
};

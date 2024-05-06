class Solution {
public:
    bool ischeck(int newx,int newy,vector<vector<char>>& grid,map<pair<int,int>,bool> &visited){
        if(newx>=0 && newx<grid.size()&& newy>=0 && newy<grid[0].size() && grid[newx][newy]=='1' && visited[{newx,newy}]==false){
            return true;
        }
        else{
        return false;
        }
    }
    void bfs(int srcx,int srcy ,vector<vector<char>>& grid,map<pair<int,int>,bool> &visited){
        queue<pair<int,int>> q;
        q.push({srcx,srcy});
        visited[{srcx,srcy}]=true;
        
        while(!q.empty()){
        pair<int,int> frontnodepair=q.front();
        q.pop();
        int tempx=frontnodepair.first;
        int tempy=frontnodepair.second;
        int x[]={-1,0,1,0};
        int y[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newx=tempx+x[i];
            int newy=tempy+y[i];
            if(ischeck(newx,newy,grid,visited)){
             q.push({newx,newy}); 
             visited[{newx,newy}]=true;
            }
        }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool> visited;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[{i,j}] && grid[i][j]=='1'){
                    bfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
    }
};

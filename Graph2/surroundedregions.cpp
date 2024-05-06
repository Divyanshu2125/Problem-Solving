class Solution {
public:
    
    void dfs(int row,int col,vector<vector<char>>&board,vector<vector<int>>&visited,int dx[],int dy[]){
     visited[row][col]=1;
     int n=board.size();
     int m=board[0].size();
     for(int i=0;i<4;i++){
        int newrow=row+dx[i];
        int newcol=col+dy[i];
        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && board[newrow][newcol]=='O' && !visited[newrow][newcol]){
            dfs(newrow,newcol,board,visited,dx,dy);
        }
     }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<m;i++){
          //First Row
          if(!visited[0][i]&&board[0][i]=='O'){
            dfs(0,i,board,visited,dx,dy);
          }
          //Last Row
          if(!visited[n-1][i] && board[n-1][i]=='O'){
            dfs(n-1,i,board,visited,dx,dy);
          }
        }
        for(int i=0;i<n;i++){
          //First Col
          if(!visited[i][0] && board[i][0]=='O'){
            dfs(i,0,board,visited,dx,dy);
          }
          //Last Col
          if(!visited[i][m-1] && board[i][m-1]=='O'){
            dfs(i,m-1,board,visited,dx,dy);
          }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

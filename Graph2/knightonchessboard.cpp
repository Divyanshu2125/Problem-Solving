int Solution::knight(int A, int B, int C, int D, int E, int F) {
    int srcx=C-1;
    int srcy=D-1;
    int desx=E-1;
    int desy=F-1;
    if(srcx==desx && srcy==desy) return 0;
    vector<vector<int>> visited(A,vector<int>(B,0));
    queue<pair<pair<int,int>,int>> q;
    visited[srcx][srcy]=1;
    q.push({{srcx,srcy},0});
    int dx[]={2,2,1,1,-2,-2,-1,-1};
    int dy[]={-1,1,2,-2,1,-1,2,-2};
    while(!q.empty()){
        int r=q.front().first.first;
        int c=q.front().first.second;
        int d=q.front().second;
        q.pop();
        if(r==desx && c==desy) return d;
        for(int i=0;i<8;i++){
            int newx=r+dx[i];
            int newy=c+dy[i];
            if(newx>=0 && newx<A && newy>=0 && newy<B && visited[newx][newy]==0){
                q.push({{newx,newy},d+1});
                visited[newx][newy]=1;
            }
        }
    }
    return -1;
}



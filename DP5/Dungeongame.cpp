class Solution {
public:
    void solve(vector<vector<int>> &dungeon ,vector<vector<int>> &dp,int n,int m){
        if(dungeon[n-1][m-1]>0) dp[n-1][m-1]=1;
        else dp[n-1][m-1]=-dungeon[n-1][m-1]+1;

        for(int i=n-2;i>=0;i--) dp[i][m-1]=max(dp[i+1][m-1]-dungeon[i][m-1],1);
        
        for(int i=m-2;i>=0;i--) dp[n-1][i]=max(dp[n-1][i+1]-dungeon[n-1][i],1);
        
       for(int i=n-2;i>=0;i--){
        for(int j=m-2;j>=0;j--){
         dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1);
        }
       }
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int n=dungeon.size();
      int m=dungeon[0].size();
      vector<vector<int>> dp(n,vector<int>(m));
       solve(dungeon,dp,n,m);
       return dp[0][0];
    }
};

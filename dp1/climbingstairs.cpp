class Solution {
public:
    
    int solve(int n,vector<int> &dp){
       if(n<=2) return n;
       if(dp[n]!=-1) return dp[n];

       int onestep=solve(n-1,dp);
       int twostep=solve(n-2,dp);
       dp[n]=onestep+twostep;
       return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans=solve(n,dp);
        return ans;

    }
};

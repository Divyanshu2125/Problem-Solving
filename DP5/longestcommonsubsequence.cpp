//USING RECURSION
// class Solution {
// public:
    
//     int solve(string text1 , string text2,int &i,int &j){
//         if(i>=text1.size() || j>=text2.size()) return 0;

//         if(text1[i]==text2[j]){ 
//             i=i+1;
//             j=j+1;
//         return 1+solve(text1,text2,i,j);
//         }
//         else{
//         i=i+1;
//         int a=solve(text1,text2,i,j); 
//         i=i-1;
//         j=j+1;
//         int b=solve(text1,text2,i,j);
//         return max(a,b);}

//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int i=0,j=0;
//         return solve(text1,text2,i,j);
        
//     }
// };

//USING MEMOISATION

// class Solution {
// public:
    
//     int solve(string &text1 , string &text2,int i,int j,vector<vector<int>> &dp){
//         if(i>=text1.size() || j>=text2.size()) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];        
//          int ans=0;
//         if(text1[i]==text2[j]) ans=1+solve(text1,text2,i+1,j+1,dp);
        
//         else ans=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
//          return dp[i][j]=ans;
//     }
    
//     int longestCommonSubsequence(string text1, string text2) {
//         int i=0,j=0,ans=0;
//         vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
//         return solve(text1,text2,i,j,dp);
        
//     }
// };

//using Tabulation
class Solution {
public:
    int solveTabulation(string text1,string text2){
     vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));

    for(int i=text1.size()-1;i>=0;i--){
        for(int j=text2.size()-1;j>=0;j--){
            int ans=0;
         if(text1[i]==text2[j]){
            ans=1+dp[i+1][j+1];
         }
         else{
            ans=max(dp[i][j+1],dp[i+1][j]);
         }
         dp[i][j]=ans;
        }
    }
     return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTabulation(text1,text2);
    }
};

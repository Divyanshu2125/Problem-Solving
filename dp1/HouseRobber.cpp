class Solution {
public:
// -------------------------Using Recursion-----------------------------------
 
    // int recursive(vector<int> & nums,int index){
    //     if(index>=nums.size()) return 0;

    //     int take=nums[index]+recursive(nums,index+2);
    //     int not_take=recursive(nums,index+1);
    //     return max(take,not_take);
    // }

// ------------------------Using Memoisation------------------------------------
  
    // int usingmemoisation(vector<int> &nums,vector<int> &dp,int index){
    //     if(index>=nums.size()) return 0;
    //      if(dp[index]!=-1) return dp[index];
    //     int take=nums[index]+usingmemoisation(nums,dp,index+2);
    //     int not_take=usingmemoisation(nums,dp,index+1);
    //     dp[index]=max(take,not_take);
    //     return dp[index];
    // }

//---------------------------Using Tabulation------------------------------------

    //   int usingtabulation(vector<int> &nums){
    //     vector<int> dp(nums.size(),-1);
    //     dp[0]=nums[0]; if(nums.size()==1) return dp[0];
    //     dp[1]=max(dp[0],nums[1]);

    //     for(int i=2;i<nums.size();i++){
    //         dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    //     }
    //     return dp[nums.size()-1];
    //   }

//----------------------------Using Space Optimization-----------------------------

     int usingspaceoptimiztion(vector<int> &nums){
        int secondprev=nums[0]; if(nums.size()==1) return secondprev;
        int firstprev=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();i++){
            int temp=secondprev;
            secondprev=firstprev;
            firstprev=max(temp+nums[i],firstprev);
        }
        return firstprev;
     }

    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int index=0;
        // return recursive(nums,index);
        // return usingmemoisation(nums,dp,index);
        // return usingtabulation(nums);
        return  usingspaceoptimiztion(nums);

    }
};

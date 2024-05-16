class Solution {
public:
// ------------------------Using Recursion--------------------
    // int usingrecursion(vector<int> &first,int index){
    //     if(index>=first.size()) return 0;
    //     int take=first[index]+usingrecursion(first,index+2);
    //     int not_take=usingrecursion(first,index+1);
    //     return max(take,not_take);
    // }
// --------------------------Using Tabulation-----------------
        // int usingtabulation(vector<int> &first){
        //     vector<int> dp(first.size(),-1);
        //     dp[0]=first[0];if(first.size()==1)return dp[0];
        //     dp[1]=max(first[0],first[1]);

        //     for(int i=2;i<first.size();i++){
        //         dp[i]=max(dp[i-2]+first[i],dp[i-1]);
        //     }
        //    return dp[first.size()-1];
        // }
// -------------------------Using Space Optimization-----------
      
         int spaceoptimization(vector<int> &first){
            int firstprev=first[0];if(first.size()==1)return firstprev;
            int secondprev=max(first[0],first[1]);

            for(int i=2;i<first.size();i++){
                int temp=secondprev;
                secondprev=max(firstprev+first[i],temp);
                firstprev=temp;
            }
           return secondprev;
         } 
// -------------------------------------------------------------
    int rob(vector<int>& nums) {
     vector<int> first;
     vector<int> second;
     if(nums.size()==1) return nums[0];
     for(int i=0;i<nums.size()-1;i++){
        int p=nums[i];
        first.push_back(p);
     }
     for(int i=1;i<nums.size();i++){
        int p=nums[i];
        second.push_back(p);
     }
    int ans1=spaceoptimization(first);
    int ans2=spaceoptimization(second);
    return max(ans1,ans2);
    }
};

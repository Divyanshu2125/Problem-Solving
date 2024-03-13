class Solution {
public:
 
    int singleNonDuplicate(vector<int>& nums) {
        
        int s=0;
        int e= nums.size()-1;

        while(s<e-1){
            int mid= s+(e-s)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!= nums[mid+1]) 
            {
                return nums[mid];
                }
            if((mid-s+1)%2==0){
                if(nums[mid]== nums[mid-1]) {
                    s=mid+1;
                    } 
                else {
                    e=mid-1;
                    }
            }
            else{
                if(nums[mid]==nums[mid-1]) {
                    e=mid-2;
                    } 
                else {
                    s=mid+2;
                    }
            }
        }
        return nums[s];
    }
};

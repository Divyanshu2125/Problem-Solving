class Solution {
public:
    int search(vector<int> nums){
        int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
         if((mid+1)<nums.size() && nums[mid]>nums[mid+1]){
            return nums[mid+1];
         }
         if((mid-1)>=0 && nums[mid]<nums[mid-1]){
            return nums[mid];
         }
         if(nums[mid]<nums[mid+1]){
            if(nums[mid]>nums[0]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }            
         }
         mid=s+(e-s)/2;
        }
        return nums[0];
    }
    
    int findMin(vector<int>& nums) {
        return search(nums);
    }
};

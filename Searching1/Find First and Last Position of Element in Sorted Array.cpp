int lastoccurence(vector<int> nums,int target){
         int s=0,e=nums.size()-1;
         int mid=s+(e-s)/2;
         int ans=-1;
         while(s<=e){
            if(nums[mid]==target){
               ans=mid;
               s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
         }
         return ans;
    }

    int firstoccurence(vector<int> nums,int target){
         int s=0,e=nums.size()-1;
         int mid=s+(e-s)/2;
         int ans=-1;
         while(s<=e){
            if(nums[mid]==target){
               ans=mid;
               e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
         }
         return ans;
    }
     
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstoccurence(nums,target);
        int last=lastoccurence(nums,target);
        vector<int> ans(2,-1);
        ans[0]=first;
        ans[1]=last;
        return ans;
    }

int BinarySearch(vector<int> arr , int target ,int s, int e){
  int mid=s+(e-s)/2;
  while(s<=e){
    if(arr[mid]==target){
      return mid;
    }
    else if(arr[mid]>target){
      e=mid-1;
    }
    else
    s=mid+1;
    mid=s+(e-s)/2;
  }
  return -1;
}

int pivotelement(vector<int> arr , int size){
  int s=0;
  int e=size-1;
  int mid=s+(e-s)/2;
  while(s<e){
    if(mid+1<size &&arr[mid]>arr[mid+1]){
      return mid;
    }
    if(mid-1>=0 &&arr[mid-1]>arr[mid]){
      return mid-1;
    }
    if(arr[s]>=arr[mid])
    {
      e=mid-1;
    }
    else
    s=mid;

    mid=s+(e-s)/2;
  }
  return s;
}
  

    int search(vector<int>& nums, int target) {
        int size=nums.size();
        int pivot=pivotelement(nums,size);
        if(target>=nums[0] && nums[pivot]>=target){
          int search=BinarySearch(nums,target,0,pivot);
          return search;
        }
        if(pivot+1<size &&pivot<size && target>=nums[pivot+1] && target<=nums[size-1]){
          int search=BinarySearch(nums,target,pivot+1,size-1);
          return search;
        }
        
    return -1; 
    }

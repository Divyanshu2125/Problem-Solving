int Pivotelement(vector<int> arr, int size){
  int s=0;
  int e=size-1;
  int mid=s+(e-s)/2;
  while(s<=e){
    if(mid+1<size &&arr[mid]>arr[mid+1]){
      return arr[mid+1];
    }
    if(mid-1>0 &&arr[mid]<arr[mid-1]){
      return arr[mid];
    }
    if(arr[s]>=arr[mid])
    {
      e=mid-1;
    }
    else
    s=mid+1;

    mid=s+(e-s)/2;
  }
  return arr[0];
}

public:
    int findMin(vector<int>& nums) {
        int size=nums.size();
    return Pivotelement(nums,size);
    }

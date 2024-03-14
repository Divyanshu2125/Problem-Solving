class Solution{
	public:
	int NthRoot(int n, int m)
	{
	  int s=0;
	  int e=m;
	  int mid=s+(e-s)/2;
	  
	  while(s<=e){
	      if(pow(mid,n)==m){
	          return mid;
	      }
	      else if(pow(mid,n)>m){
	          e=mid-1;
	      }
	      else{
	          s=mid+1;
	      }
	      mid=s+(e-s)/2;
	  }
	  return -1;
	}  
};

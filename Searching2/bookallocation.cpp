class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool ispossible(int A[],int N,int M,int mid){
        int studentCount=1;
        int sum=0;
        for(int i=0;i<N;i++){
            if(sum+A[i]<=mid){
                sum=sum+A[i];
            }
            else{
                studentCount++;
                if(M<studentCount || A[i]>mid){
                    return false;
                }
                sum=A[i];
            }
        }
        return true;
    }
    
    int findPages(int A[], int N, int M) 
    {
        int s=0;
        int sum=0;
        int ans=-1;
        if(N<M){
            return ans;
        }
        for(int i=0;i<N;i++){
            sum=sum+A[i];
        }
        int e=sum;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(ispossible(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
          mid=s+(e-s)/2;
        }
        return ans;
    }
};

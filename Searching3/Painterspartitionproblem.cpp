bool ispossible(vector<int> boards ,int k ,int mid){
    int sum=0;
    int painter=1;
    for(int i=0;i<boards.size();i++){
        if(sum+boards[i]<=mid){
            sum=sum+boards[i];
        }
        else{
           painter++;
           if(painter>k || boards[i]>mid){
               return false;
           }
           sum=boards[i];
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int s=0;
    int sum=0;
    for(int i=0;i<boards.size();i++){
     sum=sum+boards[i];
    }
    int e=sum;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(ispossible(boards,k,mid)){
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

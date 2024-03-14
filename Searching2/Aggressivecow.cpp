class Solution {
public:
    bool ispossible(int n,int k,vector<int> stalls,int mid){
        int cowcount=1;
        int lastpos=stalls[0];
        
        for(int i=0;i<n;i++){
            if(stalls[i]-lastpos>=mid){
                cowcount++;
                if(cowcount==k){
                    return true;
                }
                lastpos=stalls[i];
            }
        }
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        int s=0;
        int maxi=-1;
        int ans=-1;
        sort(stalls.begin(),stalls.end());
        for(int i=0;i<n;i++){
            maxi=max(maxi,stalls[i]);
        }
        int e=maxi;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(ispossible(n,k,stalls,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

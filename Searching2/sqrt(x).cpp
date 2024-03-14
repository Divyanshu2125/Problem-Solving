class Solution {
public:
    
    int square(int x){
        int s=0,e=x;
        long long mid=s+(e-s)/2;
        int ans=0;
        while(s<=e){
            if(mid*mid<=x){
                ans=mid;;
                s=mid+1;
            }
            else if(mid*mid>x){
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans; 
    }
    int mySqrt(int x) {
        return square(x);
    }
};

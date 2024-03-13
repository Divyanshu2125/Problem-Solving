#include<iostream>
#include<vector>
using namespace std;

int minimum(vector<int> nums){
    int s=0,e=nums.size()-1;
        int mid=s+(e-s)/2;

        while(s<e){
         if((mid+1)<nums.size() && nums[mid]>nums[mid+1]){
            return mid+1;
         }
         if((mid-1)>=0 && nums[mid]<nums[mid-1]){
            return mid;
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
        return 0;
}

int main(){
    int n;
    vector<int> nums;
    cout<<"Size the array "<<endl;
    cin>>n;
    cout<<"Enter the element"<<endl;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        nums.push_back(p);
    }
    cout<<"Find minimum element"<<endl;
    int p=minimum(nums);
    cout<<p<<endl;
    
}

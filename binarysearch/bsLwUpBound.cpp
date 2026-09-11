#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>& nums,int target){
    int ans=nums.size();
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int upperBound(vector<int> nums,int target){
    int ans=10;
    int low=0,high=nums.size()-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]>target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={1,3,7,8,8,8,9,17,32};
    int target=8;
    cout<<lowerBound(nums,target)<<endl;
    cout<<upperBound(nums,target);
}
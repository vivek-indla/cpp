#include<bits/stdc++.h>
using namespace std;
int firstOccurance(vector<int>& nums,int target){
    int low=0,high=nums.size()-1;
    int first=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            first=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return first;
}
int lastOccurance(vector<int>& nums,int target){
    int low=0,high=nums.size()-1;
    int last=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            last=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return last;
}
class Solution{
    public:
    vector<int> firstandLastOccurance(vector<int>& nums,int target){
    //brute force approach time:O(N) and space:O(1)
    // int first=-1,last=-1;
    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i]==target){
    //             if(first==-1) first=i;
    //             last=i;
    //         }
    //     }
    //     return {first,last};

    //optimal approach time:O(log N + log N) space:O(1)
    int first=firstOccurance(nums,target);
    if(first==-1) return{-1,-1};
    int last=lastOccurance(nums,target);
    return {first,last};
    }
};
int main(){
    Solution s1;
    vector<int> nums={5,7,7,8,8,10};
    int target=11;
    vector<int> result=s1.firstandLastOccurance(nums,target);
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
}
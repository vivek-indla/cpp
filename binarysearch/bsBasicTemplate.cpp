#include<bits/stdc++.h>
using namespace std;
//iterative approach time:O(log N ) space:O(1)
// int search(vector<int>& nums,int target){
//     int low=0;
//     int high=nums.size();
//     while(low<=high){
//         int mid=low+(high-low)/2;
//         if(nums[mid]==target){
//             return mid;
//         }
//         else if(nums[mid]<target){
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     return -1;
// }

//recursive approach time:O(log N) space:O(log N)
int helper(vector<int>& nums,int low,int high,int target){
    if(low>high){
        return -1;
    }
    int mid=low+(high-low)/2;
    if(nums[mid]==target){
        return mid;
    }
    else if(nums[mid]<target){
        return helper(nums,mid+1,high,target);
    }
    return helper(nums,low,mid-1,target);
}

int search(vector<int> nums,int target){
    return helper(nums,0,nums.size()-1,target);
}
int main(){
    vector<int> nums={1,3,5,8,19,27,34,79};
    int target=79;
    cout<<search(nums,target);
}
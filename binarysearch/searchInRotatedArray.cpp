#include<bits/stdc++.h>
using namespace std;
int searchInRotated(vector<int> &nums,int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[left]<=nums[mid]){
            if(nums[left]<=target && nums[mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        else{
            if(nums[mid]<target && nums[right]>=target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums={7,8,9,15,32,2,4,6};
    int target=2;
    cout<<searchInRotated(nums,target);
    return 0;
}
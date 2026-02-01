#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int> &nums,int target){
    int start=0;
    int end=nums.size()-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> nums={1,2,3,4,5,6,7};
    int target=1;
    cout<<binarysearch(nums,target);
    return 0;
}
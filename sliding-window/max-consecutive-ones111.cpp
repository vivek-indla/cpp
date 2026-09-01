#include<bits/stdc++.h>
using namespace std;
int maxConsecutiveOnes(vector<int>& nums,int k){

    // brute force approach time:O(n^2) and space:O(1)
    // int maxlen=0;
    // for(int i=0;i<nums.size();i++){
    //     int zeros=0;
    //     for(int j=i;j<nums.size();j++){
    //         if(nums[j]==0) zeros++;
    //         if(zeros > k) continue;
    //         maxlen=max(maxlen,j-i+1);
    //     }
    // }
    // return maxlen;
    // 
    // better approach time: O(2N) for left and right and space: O(1)
    // int maxlen=0,left=0,right=0,zeros=0;
    // while(right<nums.size()){
    //     if(nums[right]==0) zeros++;
    //     while(zeros > k){
    //         if(nums[left]==0) zeros--;
    //         left++;
    //     }
    //     maxlen=max(maxlen,right-left+1);
    //     right++;
    // }
    // return maxlen;

    // optimal approach time:O(N) and space:O(1)
    int maxlen=0,left=0,right=0,zeros=0;
    while(right<nums.size()){
        if(nums[right]==0) zeros++;
        if(zeros > k){
            if(nums[left]==0) zeros--;
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}
int main(){
    vector<int> nums={1,1,1,0,0,0,0,1,1,1,1,1};
    int k=2;
    cout<<maxConsecutiveOnes(nums,k);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int maxPointsObtainedFromCards(vector<int> nums,int k){
    int leftSum=0;
    for(int i=0;i<k;i++){
        leftSum+=nums[i];
    }
    int left=k-1,right=nums.size()-1;
    int maxSum=leftSum;
    while(k--){
        leftSum-=nums[left--];
        leftSum+=nums[right--];
        maxSum=max(maxSum,leftSum);
    }
    return maxSum;
}
int main(){
    vector<int> nums={1,2,3,4,5,6,1};
    int k=3;
    cout<<maxPointsObtainedFromCards(nums,k);
    return 0;
}
    #include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int>& nums){
    int left=0,right=0;
    while(right<nums.size()){
        if(nums[right]!=nums[left]){
            left++;
            swap(nums[right],nums[left]);
        }
        right++;
    }
    return left+1;
}
};
int main(){
    Solution s1;
    vector<int> nums={1,1,2,2,2,3,3};
    int index=s1.removeDuplicates(nums);
    for(int i=0;i<index;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
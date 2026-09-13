#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeros(vector<int>& nums) {
       int left=0,right=0;
       while(right<nums.size()){
            if(nums[right]!=0){
                swap(nums[right],nums[left]);
                left++;
            }
            right++;
       } 
    }
};
int main(){
    Solution s1;
    vector<int> nums={1,0,0,3,12};
    s1.moveZeros(nums);
    for(int i:nums){
        cout<<i<<" ";
    }
}
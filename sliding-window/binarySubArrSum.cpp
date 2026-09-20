#include<bits/stdc++.h>
using namespace std;
int findGoal(vector<int>& nums,int goal){
    int left=0,right=0,sum=0,count=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>goal){
                sum-=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
    return count;
}
class Solution{
    public:
    int binarySubArrSum(vector<int>& nums,int goal){
        return findGoal(nums,goal)-findGoal(nums,goal-1);
    }
};
int main(){
    Solution s1;
    vector<int> nums={1,0,1,0,1};
    int goal=2;
    cout<<s1.binarySubArrSum(nums,goal);
    return 0;
}
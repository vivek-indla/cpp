#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void rotateArrayByOne(vector<int>& nums){
        int n=nums.size();
        int temp=nums[0];
        for(int i=0;i<n;i++){
            nums[i-1]=nums[i];
        }
        nums[n-1]=temp;
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
    }
};
int main(){
    Solution s1;
    vector<int> nums={1,2,3,4,5};
    s1.rotateArrayByOne(nums);
    return 0;
}
    #include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int> &nums){
        if(nums.size()<=1){
            return nums.size();
        }
        int idx=1;
        for(int i=1;i<nums.size();i++){
            if(nums[idx]!=nums[i-1]){
                nums[idx++]=nums[i];
                idx++;
            }
        }
        return idx;
    }
};
int main(){
    Solution s1;
    vector<int> nums={1,2,2,3,3, 4, 4, 4, 5, 5};
    int newSize=s1.removeDuplicates(nums);
    for(int i=0;i<newSize;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
// push all zeros to end
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public: 
        void moveZerosToEnd(vector<int> &nums){
            int start=0;
            int streak=0;
            while(start<nums.size() && streak<nums.size()){
               if(nums[streak]==0){
                    start++;
                    if(nums[start]!=0){
                        int swap=nums[start];
                        nums[start]=nums[streak];
                        nums[streak]=swap;
                        streak++;
                    }
                    continue;
               }
               start++;
               streak++;
            }
            for(int i:nums){
                cout<<i<<" "<<endl;
            }
        }
};

int main(){
    Solution s1;
    vector<int> nums={1,0,2,0,0,3,4,0};
    s1.moveZerosToEnd(nums);
    return 0;
}
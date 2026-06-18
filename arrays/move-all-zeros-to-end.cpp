#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void moveZerosToEnd(vector<int>& nums){
        int n=nums.size();
        int x=0;
        int y=0;
        while(x<=n && y<=n){
            if(nums[y]==0){
                x++;
                if(nums[x]!=0){
                    swap(nums[x],nums[y]);
                    y++;
                }
                continue;
            }
            x++;
            y++;
        }
        for(int i:nums){
            cout<<i<<" ";
        }
    }
};
int main(){
    Solution s1;
    vector<int> nums={1 ,0 ,2 ,3 ,0 ,4 ,0 ,1};
    s1.moveZerosToEnd(nums);
    return 0;
}
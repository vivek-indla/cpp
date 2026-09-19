#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int singleELementInArray(vector<int>& nums){
        int ans=0;
        for(int i:nums){
            ans^=i;
        }
        return ans;
    }
};
int main(){
    Solution s1;
    vector<int> nums={1,1,2,3,7,7,3,2,9};
    cout<<s1.singleELementInArray(nums);
    return 0;
}
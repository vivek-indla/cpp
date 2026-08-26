#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int longestSubarrayWithK(vector<int>& nums,int k){
    int n=nums.size();
    int left=0,right=0,maxlen=0,sum=0;
    while(right<=n){   
        sum+=nums[right];
        if(sum > k){
            sum-=nums[left];
            left++;
        }
        if(sum<=k){
            maxlen=max(maxlen,right-left+1);
        }
        right++;
    }
    return maxlen;
    }
};
int main(){
    Solution s1;
    vector<int> nums={14,5,1,8,10};
    int ans=s1.longestSubarrayWithK(nums,13);
    cout<<ans<<endl;
}
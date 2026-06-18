// equilibrium index indicates the middle index which has the same values at left and right 
// ex: 
// 1 3 2 9 4 1 1 
// equilibrium index is 3 because it left sum is 6 and right sum is 6

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int equilibriumCheck(vector<int> &nums){
        int start=0,left_sum=0;
        left_sum+=nums[start];
        int end=nums.size()-1,right_sum=0;
        right_sum+=nums[end];
        while(start <= end){
            start++;
            end--;
            if(left_sum < right_sum){
                left_sum+=nums[start];
            }
            else{
            right_sum+=nums[end];
            }
            if(left_sum==right_sum){
                return start+1;
            }
        }
        return -1;
    }
};

int main(){
    Solution s1;
    vector<int> nums={1,3,2,9,4,1,1};
    int index=s1.equilibriumCheck(nums);
    cout<<index<<" "<<endl;
    return 0;
}
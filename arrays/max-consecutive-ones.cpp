#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maxConsecutiveOnes(vector<int> &nums){
    int count=0,maxm=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            count++;
        }
        else{
            count=0;
        }
        maxm=max(count,maxm);
    }
    return maxm;
}
};

int main() {
    Solution s1;
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    cout << "Maximum Consecutive Ones are: "
         << s1.maxConsecutiveOnes(nums);

    return 0;
}

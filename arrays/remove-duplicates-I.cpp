// In this program we are going to remove duplicates of the sorted order numbers 
// using two pointers 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int remove_duplicates(vector<int> &nums){
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

int main(){
    Solution s1;
    vector<int> nums={0,0,0,1,1,2,2,2,3,3};
    int k = s1.remove_duplicates(nums);
    cout<<"count of unique numbers: "<<k<<endl;
    cout<<"Array after removing duplicates: ";
    for(int i=0;i<k;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}
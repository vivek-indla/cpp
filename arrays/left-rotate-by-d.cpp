#include<bits/stdc++.h>
using namespace std;

//brute force approach time=O(n*d*temp) and space=O(n*d)
// class Solution{
//     public:
//     void rotateByD(vector<int>& nums,int d){
//         int n=nums.size();
//         if(d>n){
//             d%=n;
//         }
//         vector<int> temp;
//         for(int i=0;i<d;i++){
//             temp.push_back(nums[i]);
//         }
//         for(int i=d;i<n;i++){
//             nums[i-d]=nums[i];
//         }
//         for(int i=d+1;i<n;i++){
//             nums[i]=temp[i-(n-d)];
//         }
//          for(int i=0;i<nums.size();i++){
//         cout<<nums[i]<<" ";
//     }
//     }
// };

class Solution{
    public:
    void reverseArray(vector<int>& nums,int start,int end){
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void rotateByD(vector<int>& nums,int d){
        int n=nums.size();
        if(d>n){
            d%=n;
        }
        reverseArray(nums,0,d-1);
        reverseArray(nums,d,n-1);
        reverseArray(nums,0,n-1);
        for(int i:nums){
            cout<<i<<" ";
        }
    }
};  
int main(){
    Solution s1;
    vector<int> nums={1,2,3,4,5,6};
    int d=10;
    s1.rotateByD(nums,d);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> intersectionOfSorted(vector<int>& nums1,vector<int>& nums2,int n,int m){
        int i=0,j=0;
        vector<int> intersection;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j]){
                j++;
            }
            else{
                // if(intersection.empty() || intersection.back()!=nums1[i]){
                    intersection.push_back(nums1[i]);
                // }
                i++;
                j++;
            }
        }
        return intersection;
    }
};
int main(){
    Solution s1;
    vector<int> nums1={1, 1, 2, 2, 2, 4};
    vector<int> nums2={2, 2, 4, 4};
    int n=nums1.size();
    int m=nums2.size();
    vector<int> result=s1.intersectionOfSorted(nums1,nums2,n,m);
    for(auto &i:result){
        cout<<i<<" ";
    }
}
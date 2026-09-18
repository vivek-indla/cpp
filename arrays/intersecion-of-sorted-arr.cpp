#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> Intersection(vector<int>& nums1,vector<int>& nums2){
        // time : O(n log n) for sorting arrays space:O(!)
        if arrays are not sorted
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> intersect;
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                if(intersect.empty() || intersect.back()!=nums1[i]){
                    intersect.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i]<nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
    //     return intersect;

        // //time ;O(n) and space:O(n)
        // unordered_set<int> set1(nums1.begin(),nums1.end());
        // unordered_set<int> set2(nums2.begin(),nums2.end());
        // vector<int> result;
        // for(const auto& i:set1){
        //     if(set2.find(i)!=set2.end()){
        //         result.push_back(i);
        //     }
        // }
        // return result;
    }
};
int main(){
    Solution s1;
    vector<int> nums1={4,9,5};
    vector<int> nums2={9,4,9,8,4};
    vector<int> result=s1.Intersection(nums1,nums2);
    for(int i:result){
        cout<<i<<" ";
    }
    return 0;
}
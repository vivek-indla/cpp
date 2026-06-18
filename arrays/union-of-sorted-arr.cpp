#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find union of two sorted arrays using two pointers
    vector<int> findUnion(vector<int>& nums1,vector<int>& nums2, int n, int m) {
     vector<int> Union;
     int i=0,j=0;
     while(i<n && j<m){
        if(nums1[i] < nums2[j]){
            if(Union.empty() || Union.back()!=nums1[i])
                Union.push_back(nums1[i]);
            i++;
        }
        else if(nums1[i] > nums2[j]){
            if(Union.empty() || Union.back()!=nums2[j])
                Union.push_back(nums2[j]);
            j++;
        }
        else{
            if(Union.empty() || Union.back()!=nums1[i])
                Union.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    while(i<n){
        if(Union.empty() || Union.back()!=nums1[i])
                Union.push_back(nums1[i]);
            i++;    
     }
    while(j<m){
        if(Union.empty() || Union.back()!=nums2[j])
                Union.push_back(nums2[j]);
            j++;
     }
    return Union;
    }
     
};

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2 = {2, 3, 4, 4, 5, 11, 12};
    int n = nums1.size(), m = nums2.size();

    Solution obj;
    vector<int> result = obj.findUnion(nums1,nums2, n, m);

    cout << "Union of arr1 and arr2 is: ";
    for (int val : result) cout << val << " ";
    return 0;
}

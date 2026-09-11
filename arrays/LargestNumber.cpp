#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int largestNo(vector<int>& arr){
        int largest=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]>largest){
                largest=arr[i];
            }
        }
        return largest;
    }
};
int main(){
    Solution s1;
    vector<int> nums={0,1,2,2};
    cout<<s1.largestNo(nums);
    return 0;
}
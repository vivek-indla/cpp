#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        map<int,int> mapp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int search=target-arr[i];
            if(mapp.find(search)!=mapp.end()){
                return {mapp[search],i};
            }
            mapp[arr[i]]=i;
        }
        return {-1,-1};
    }
};
int main(){
    Solution s1;
    vector<int> nums={2,7,11,15};
    int target=9;
    vector<int> res=s1.twoSum(nums,target);
    for(int i:res){
        cout<<i<<" ";
    }
    return 0;
}
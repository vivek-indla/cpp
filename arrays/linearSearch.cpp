#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int linearSearch(vector<int>& arr,int target){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==target){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s1;
    vector<int> arr={3,5,8,6,9};
    int target=6;
    cout<<s1.linearSearch(arr,target);
    return 0;
}
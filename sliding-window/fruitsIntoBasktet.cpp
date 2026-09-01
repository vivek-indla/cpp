#include<bits/stdc++.h>
using namespace std;
// brute force approach time: O(N^2) and space: O(3) for storing atmost 3 different types of fruits
// int fruitsIntoBasket(vector<int>& nums,int k){
// int maxlen=0;
//     set<int> st;
//     for(int i=0;i<nums.size();i++){
//         for(int j=i;j<nums.size();j++){
//             if(st.size()>k) continue;
//             st.insert(nums[j]);
//             maxlen=max(maxlen,j-i+1);
//         }
//     }
//     return maxlen;
// }

//below is optimal time: O(N) and space: O(3) for storing k different types of fruits
int fruitsIntoBasket(vector<int>& nums,int k){
    int maxlen=0;
    int left=0,right=0;
    map<int,int> hashh;
    while(right<nums.size()){
        hashh[nums[right]]++;
        if(hashh.size()>k){
            hashh[nums[left]]--;
            if(hashh[nums[left]]==0){
                hashh.erase(nums[left]);
            }
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}
int main(){
    vector<int> nums={3,3,3,1,2,1,1,2,3,3,4};
    int k=2;
    cout<<fruitsIntoBasket(nums,k);
    return 0;
}
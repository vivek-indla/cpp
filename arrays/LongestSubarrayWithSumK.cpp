#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int LongestSubArrWithSumK(vector<int>& arr,int k){
        int sum=0,maxlen=0;
        map<int,int> preSumMap;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
            }
            int rem=sum-k;
            if(preSumMap.find(rem)!=preSumMap.end()){
                int len=i-preSumMap[rem];
                maxlen=max(maxlen,len);
            }
            if(preSumMap.find(sum)==preSumMap.end()){
                preSumMap[sum]=i;
            }
        }
        return maxlen;
    }
};
int main(){
    Solution s1;
    vector<int> nums={10,5,2,7,1,-10};
    int k=15;
    cout<<s1.LongestSubArrWithSumK(nums,k);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //brute force time: O(n^2)  and space: O(256)
    //     int maxlen=0;
    //     for(int i=0;i<s.size();i++){
    //         int hash[256]={0};
    //         for(int j=i;j<s.size();j++){
    //             if(hash[s[j]]!=0) break;
    //             hash[s[j]]++;
    //             maxlen=max(maxlen,j-i+1);
    //         }
    //     }
    //     return maxlen;

    //optimal approach time:O(N) and space:O(256)
    int hash[256]={-1};
    int right=0,left=0,maxlen=0;
    while(right<s.size()){
        if(hash[s[right]]!=-1){
            left=max(hash[s[right]]+1,left);
        }
        maxlen=max(maxlen,right-left+1);
        hash[s[right]]=right;
        right++;
    }
    return maxlen;
    }
};
int main(){
  Solution s1;
  string s="pwwkew";
  cout<<s1.lengthOfLongestSubstring(s);
  return 0;
}
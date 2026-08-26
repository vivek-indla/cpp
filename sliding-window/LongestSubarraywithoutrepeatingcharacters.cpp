#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
   int lengthOfLongestSubstring(string s){
        int mapp[256]={-1};
        int left=0,right=0,n=s.size();
        int maxlen=0;
        while(right<n){
            if(mapp[s[right]]!=-1){
                left=max(mapp[s[right]]+1,left);
            }
            maxlen=max(maxlen,right-left+1);
            mapp[s[right]]=right;
            right++;
        }
        return maxlen;
   }
};
int main(){
    Solution s1;
    string s="abcabcbbc";
    int len=s1.lengthOfLongestSubstring(s);
    cout<<len<<endl;
    return 0;
}
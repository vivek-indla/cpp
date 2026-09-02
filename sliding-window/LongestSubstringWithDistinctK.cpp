#include<bits/stdc++.h>
using namespace std;
int LongestSubstringDistinctK(string s,int k){

    // brute force approach time:O(n^2) and space:O(k+1)
    // int maxlen=0;
    // set<char> st;
    // for(int i=0;i<s.size();i++){
    //     for(int j=i;j<s.size();j++){
    //         st.insert(s[j]);
    //         if(st.size()> k) continue;
    //         maxlen=max(maxlen,j-i+1);
    //     }
    // }
    // return maxlen;

    //better approach time:O(2N)+O(log 256) and space:O(256)
    // int maxlen=0,left=0,right=0;
    // map<char,int> hashh;
    // while(right<s.size()){
    //     hashh[s[right]]++;
    //     while(hashh.size() > k){
    //         hashh[s[left]]--;
    //         if(hashh[s[left]]==0) hashh.erase(s[left]);
    //         left++;
    //     }
    //     maxlen=max(maxlen,right-left+1);
    //     right++;
    // }
    // return maxlen;

    //optimal approach time:O(N)+O(log 256) and space:O(log 256)
    int maxlen=0,left=0,right=0;
    map<char,int> hashh;
    while(right<s.size()){
        hashh[s[right]]++;
        if(hashh.size() > k){
            hashh[s[left]]--;
            if(hashh[s[left]]==0) hashh.erase(s[left]);
            left++;
        }
        maxlen=max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}
int main(){
    string s="aaabbccd";
    int k=2;
    cout<<LongestSubstringDistinctK(s,k);
}
#include<bits/stdc++.h>
using namespace std;
int LongestRepeatingReplacement(string s,int k){
    // int maxlen=0;
    // for(int i=0;i<s.size();i++){
    //     int hash[26]={0};
    //     int maxfrq=0;
    //     for(int j=i;j<s.size();j++){
    //         hash[s[j]-'A']++;
    //         maxfrq=max(maxfrq,hash[s[j]-'A']);
    //         int changes=(j-i+1)-maxfrq;
    //         if(changes<=k){
    //             maxlen=max(maxlen,j-i+1);
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // return maxlen;
    // brute approach time: O(N^2) and space: O(26)

    //optimal approach
    int right=0,left=0,maxlen=0,maxfreq=0;
        int hash[26]={0};
        while(right<s.size()){
            hash[s[right]-'A']++;
            maxfreq=max(maxfreq,hash[s[right]-'A']);
            if((right-left+1)-maxfreq > k){
                hash[s[left]-'A']--;
                left++;
            }
            if((right-left+1)-maxfreq <= k){
                maxlen=max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
}

int main(){
    string s="AAABABBA";
    int k=2;
    cout<<LongestRepeatingReplacement(s,k);
    return 0;
}
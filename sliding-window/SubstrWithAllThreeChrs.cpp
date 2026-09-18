#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int SubstrWithAllThreeChrs(string& s){
        int res=0;
        int right=0,left=0;
        vector<int> freq(3,0);
        while(right<s.size()){
            freq[s[right]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                res+=(s.size()-right);
                freq[s[left]-'a']--;
                left++;
            }
            right++;
        }
        return res;
    }
};
int main(){
    Solution s1;
    string s="abcabc";
    cout<<s1.SubstrWithAllThreeChrs(s);
    return 0;
}
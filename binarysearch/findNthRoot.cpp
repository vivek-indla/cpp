#include<bits/stdc++.h>
using namespace std;
// if ans==2 remove 2nd half
// if ans==1 it found
// if ans==0 remove 1st half
int check(int mid,int m,int n){
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans*=mid;
        if(ans>m) return 2;
    }
    if(ans==m) return 1;
    return 0;
}
class Solution{
    public:
    int findNthRoot(int m,int n){
        int low=1,high=m;
        while(low<=high){
            int mid=(low+high)/2;
            int midN=check(mid,m,n);
            if(midN==1) return mid;
            else if(midN==0){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};
int main(){
    Solution s1;
    int m=82;
    int n=4;
    cout<<s1.findNthRoot(m,n);
    return 0;
}
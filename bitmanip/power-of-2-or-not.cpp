#include<iostream>
using namespace std;
class Solution{
    public:
    int set=0;
    bool isPowerOfTwo(int n){
        while(n){
            if(n&1){
                set++;
            }
            n=n>>1;
        }
        return set==1;
    }
};
int main(){
    Solution sol;
    int n=64;
    // cout<<"enter a number: ";
    // cin>>n;
    bool check=sol.isPowerOfTwo(n);
    if(check){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
    return 0;
}
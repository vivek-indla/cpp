#include<iostream>
using namespace std;
class Solution{
    public:
        int rightMostSetBit(int n){
            int digit=n&1;
            if(digit==1){
                return n;
            }
            else{
                return n+1;
            }
        }
};
int main(){
    Solution sol;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<sol.rightMostSetBit(n);
    return 0;
}
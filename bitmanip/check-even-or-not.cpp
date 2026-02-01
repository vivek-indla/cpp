#include<iostream>
using namespace std;
class Solution{
    public:
        int check(int n){
            return (n&1)==0;
        }
};
int main(){
    Solution sol;
    int n;
    cout<<"enter a number: ";
    cin>>n;
    bool check=sol.check(n);
    if(check){
        cout<<"Even Number";
    }
    else{
        cout<<"Odd Number";
    }
    return 0;
}
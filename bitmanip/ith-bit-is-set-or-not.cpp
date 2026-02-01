#include<iostream>
using namespace std;
class Solution{
    public:
    int set(int n,int i,int size){
        int test=size-i-1;
        int check=n>>test;
    }
};
int main(){
    Solution sol;
    int n, i;
    cout<<"enter the number and position : ";
    cin>>n>>i;
    int size=0;
    int temp=n;
    while(temp){
        size++;
        temp=temp>>1;
    }
    int check=sol.set(n,i,size);
    if(check&1){
        cout<<"Set Bit";
    }
    else{
        cout<<"Not Set Bit";
    }
    return 0;
}
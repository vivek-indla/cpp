#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number: ";
    cin>>n;
    if(n&1){
        cout<<"odd"<<endl;
    }
    else{
        cout<<"even"<<endl;
    }
    return 0;
}
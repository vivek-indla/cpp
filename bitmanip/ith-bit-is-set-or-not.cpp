#include<iostream>
using namespace std;
int main(){
    int n=10, i=1;
    // cout<<"enter a number and position: ";
    // cin>>n>>i;
    int set=n>>i;
    cout<<set<<endl;
    if(set&1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
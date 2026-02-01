#include<iostream>
using namespace std;
int main(){
    int n=15,i=2;
    int size=0;
    while(n){
        size++;
        n=n>>1;
    }
    int set=size-i-1;
    if(set&1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
#include<iostream>
using namespace std;
class Solution{
    public:
    int countSetBits(int n){
        int count=0;
        while(n){
            int digit=n&1;
            if(digit==1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};
int main(){
    Solution sol;
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int result=sol.countSetBits(n);
    cout<<result<<endl;
    return 0;
}
#include<iostream>
using namespace std;
class Solution{
    public: 
        int division(int dividend, int divisor){
            int count=0;
            while(dividend-divisor>=divisor)
            {
                dividend=dividend-divisor;
                count++;
            }
            return count+1;
        }

};
int main(){
    Solution sol;
    int dividend,divisor;
    cout<<"Enter dividend and divisor: ";
    cin>>dividend>>divisor;
    cout<<sol.division(dividend,divisor);
    return 0;
}
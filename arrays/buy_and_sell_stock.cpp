/*
buy and sell stock only one time 
time complexity: O(n)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int result(vector<int> &price){
        int min=INT_MAX;
        int size=price.size();
        for(int i=0;i<size;i++){
            if(min>price[i]){
                min=price[i];
            }
        }
        int MAX=-1;
        for(int i=min;i<size;i++){
            int cost=price[i]-min;
            MAX=max(cost,MAX);
        }
        return MAX;
    }
};

int main(){
    Solution s1;
    vector<int> price={10,2,1,3,5,25,35,20,90,24};
    cout<<s1.result(price);
    return 0;
}
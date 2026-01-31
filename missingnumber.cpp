#include<iostream>
#include<vector>
using namespace std;
int missing(vector<int> &nums){
    int sum=0;
    for(int i=0;i<=nums.size();i++){
        sum+=i;
    }
    int vsum=0;
    for(auto i:nums){
        vsum+=i;
    }
    return sum-vsum;
}
int main(){
    vector<int> nums={3,0,2,1};
    cout<<missing(nums);
    return 0;
}
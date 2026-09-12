#include<bits/stdc++.h>
using namespace std;
bool isSorted(vector<int>& arr){
    for(int i=1;i<arr.size();i++){
        if(arr[i]>=arr[i-1]){
            continue;
        }
        return false;
    }
    return true;
}
int main(){
    vector<int> nums={0,1,1,2,1,6,9,15};
    bool ans=isSorted(nums);
    if(ans) cout<<"true";
    else cout<<"false";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int secondLargestNo(vector<int>& arr){
        //better approach time: O(2n) and space:O(1)
        // int largest=arr[0];
        // for(int i=1;i<arr.size();i++){
        //     if(arr[i]>largest){
        //         largest=arr[i];
        //     }
        // }
        // int secondLargest=-1;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]>secondLargest && arr[i]!=largest){
        //         secondLargest=arr[i];
        //     }
        // }
        // return secondLargest;

        //optimal approach time:O(N) and space:O(1)
        int largest=-1,secLargest=-1;
                for(int i=0;i<arr.size();i++){
                    if(arr[i]>largest){
                        secLargest=largest;
                        largest=arr[i]; 
                    }
                    if(arr[i]>secLargest && arr[i]!=largest){
                        secLargest=arr[i];
                    }
        }
        return secLargest;
    }
};
int main(){
    Solution s1;
    vector<int> nums={0,1,2,2};
    cout<<s1.secondLargestNo(nums);
    return 0;
}
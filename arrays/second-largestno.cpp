#include<iostream>
#include<climits>
using namespace std;
class Solution{
    public:
    int secondLargest(int arr[],int n){
        int largest=INT_MIN;
        int secondlargest=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                secondlargest=largest;
                largest=arr[i];
            }
            else if(arr[i]>secondlargest && arr[i]!=largest){
                secondlargest=arr[i];
            }
        }
        return secondlargest;
    }
};
int main(){
    Solution sol;
    int n=5;
    // // cin>>n;
    int arr[5] = {10, 20, 30, 89, 50};
    // for(int i=0;i<n;i++){
    //     cin>>arr[i];
    // }
    int secondlargest=sol.secondLargest(arr,n);
    cout<<secondlargest<<endl;
    return 0;
}
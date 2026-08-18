#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* convert(vector<int> &nums){
    ListNode* head=new ListNode(nums[0]);
    ListNode* mover=head;
    for(int i=1;i<nums.size();i++){
        ListNode* temp=new ListNode(nums[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
bool palindrome(ListNode* head){
    stack<int> st;
    ListNode* temp=head;
    while(temp){
        st.push(temp->val);
        temp=temp->next;
    }
    temp=head;
    while(temp){
        int value=st.top();
        if(temp->val!=value){
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
}
int main(){
    vector<int> nums={9};
    ListNode* head=convert(nums);
    bool flag=palindrome(head);
    if(flag){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    // print(head);
}
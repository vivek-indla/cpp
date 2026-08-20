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
 ListNode* reverseList(ListNode* head){
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr){
        ListNode* temp=curr->next;
        curr->next=temp;
        prev=curr;
        curr=temp;
    }
    return prev;
 }
bool palindrome(ListNode* head){
    // stack<int> st;
    // ListNode* temp=head;
    // while(temp){
    //     st.push(temp->val);
    //     temp=temp->next;
    // }
    // temp=head;
    // while(temp){
    //     int value=st.top();
    //     if(temp->val!=value){
    //         return false;
    //     }
    //     st.pop();
    //     temp=temp->next;
    // }
    // return true;
    //above is brute force approach
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHead=reverseList(slow->next);
        ListNode* first=head;
        ListNode* second=secondHead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverseList(secondHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseList(secondHead);
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
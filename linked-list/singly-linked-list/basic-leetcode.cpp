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
//leetcode 203
ListNode* removeValue(ListNode* head,int value){
    if(head==NULL){
        return head;
    }
    while(head!=NULL && head->val==value){
        ListNode* temp=head;
        head=head->next;
        delete temp;
    }
    ListNode* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->next->val==value){
            ListNode* del=temp->next;
            temp->next=del->next;
            delete del;
        }
        else{
            temp=temp->next;
        }
    }
    
    return head;
}
//leetcode 83
ListNode* removeDuplicates(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val==temp->next->val){
                ListNode* del=temp->next;
                temp->next=del->next;
                delete del;
            }
            else{
            temp=temp->next;
            }
        }
        return head;
        
}
int main(){
    vector<int> nums={4,5,1,9};
    ListNode* head=convert(nums);
    // head=removeValue(head,3);
    // head=removeDuplicates(head);
    print(head);
}
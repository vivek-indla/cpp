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
ListNode* createLoop(ListNode* head){
    ListNode* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    tail->next=head;
    return head;
}
int lengthLL(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=slow->next;
            int count=1;
            while(slow!=fast){
                count++;
                slow=slow->next;
            }
            return count;
        }
    }
    return 0;
}
//recursive 
ListNode* reverseList(ListNode* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    ListNode* newHead=reverseList(head->next);
    ListNode* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
//iterative
ListNode* itrv_reverseList(ListNode* head){
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

int main(){
    vector<int> nums={0,1,1};
    ListNode* head=convert(nums);
    head=reverseList(head);
    print(head);
    return 0;
}
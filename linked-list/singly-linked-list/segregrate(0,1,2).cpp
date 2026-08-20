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
ListNode* sort(ListNode* head){
    ListNode* dummyZero=new ListNode(-1);
    ListNode* dummyOne=new ListNode(-1);
    ListNode* dummyTwo=new ListNode(-1);
    ListNode* zero=dummyZero;
    ListNode* one=dummyOne;
    ListNode* two=dummyTwo;
    ListNode* temp=head;
    while(temp){
        if(temp->val==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->val==1){
            one->next=temp;
            one=temp;
        }
        else{
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=dummyOne->next;
    one->next=dummyTwo->next;
    return dummyZero->next;
}
int main(){
    vector<int> nums={0,1,1,2,1,0,2};
    ListNode* head=convert(nums);
    head=sort(head);
    print(head);
    return 0;
}
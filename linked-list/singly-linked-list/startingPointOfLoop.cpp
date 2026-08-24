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
void createLoop(ListNode* head){
    ListNode* temp=head;
    while(temp->next)
        temp=temp->next;
    temp->next=head->next->next;
}
void print(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
ListNode* startingPoint(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}
void pos(ListNode* head,ListNode* required){
    ListNode* temp=head;
    int count=0;
    if(required==NULL){
        cout<<"No loop detected"<<endl;
        return ;
    }
    while(temp && temp!=required){
        count++;
        temp=temp->next;
    }
    cout<<"tail points to index: "<<count<<endl;
}
int main(){
    vector<int> nums={4,5,1,9};
    ListNode* head=convert(nums);
    createLoop(head);
    ListNode* required=startingPoint(head);
    pos(head,required);
}
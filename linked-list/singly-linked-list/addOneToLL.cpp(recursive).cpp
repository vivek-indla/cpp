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
int helper(ListNode* head){
   ListNode* temp=head;
   if(temp==NULL){
       return 1;
   }
   int carry=helper(temp->next);
   temp->val+=carry;
   if(temp->val==10){
       temp->val=0;
       return 1;
   }
   return 0;
}
ListNode* addOne(ListNode* head){
    int carry=helper(head);
    if(carry){
        ListNode* newNode=new ListNode(carry);
        newNode->next=head;
        return newNode;
    }
    return head;
}
int main(){
    vector<int> nums={9,9,9};
    ListNode* head=convert(nums);
    head=addOne(head);
    print(head);
}
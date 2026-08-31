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
ListNode* findMiddle(ListNode* head){
    ListNode* slow=head;
    ListNode* fast=head;
    while(!fast || !fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
// brute force approach time: O(N) for traversing and converting in time and space: O(N) for storing temporarily
// ListNode* sortList(ListNode* head){
//     vector<int> nums;
//     ListNode* temp=head;
//     while(temp){
//         nums.push_back(temp->val);
//         temp=temp->next;
//     }
//     sort(nums.begin(),nums.end());
//     return convert(nums);
// }
ListNode* merge(ListNode* list1,ListNode* list2){
    ListNode* dummy=new ListNode(-1);
    ListNode* traverse=dummy;
    while(list1 && list2){
        if(list1->val < list2->val){
            traverse->next=list1;
            list1=list1->next;
        }
        else{
            traverse->next=list2;
            list2=list2->next;
        }
        traverse=traverse->next;
    }
    if(list1) traverse->next=list1;
    else traverse->next=list2;
    return dummy->next;
}
ListNode* sortList(ListNode* head){
    if(!head || !head->next){
        return head;
    }
    ListNode* middle=findMiddle(head);
    ListNode* left=head;
    ListNode* right=middle->next;
    middle->next=NULL;
    left=sortList(left);
    right=sortList(right);
    return merge(left,right);
}
int main(){
    vector<int> nums={4,5,1,9};
    ListNode* head=convert(nums);
    head=sortList(head);
    print(head);
}
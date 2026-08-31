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
ListNode* findInsertion(ListNode* head1,ListNode* head2){
    int l1=0,l2=0;
    ListNode* temp=head1;
    while(temp){
        l1++;
        temp=temp->next;
    }
    temp=head2;
    while(temp){
        l2++;
        temp=temp->next;
    }
    int diff=abs(l1-l2);
    if(l1>l2){
        while(diff--){
            head1=head1->next;
        }
    }
    else{
        while(diff--){
            head2=head2->next;
        }
    }
    ListNode* temp1=head1;
    ListNode* temp2=head2;
    while(temp1){
        if(temp1==temp2){
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
}
    return NULL;
}
int main(){
    vector<int> nums={4,5,1,9,2,3};
    ListNode* head=convert(nums);
    ListNode* head1=head;
    vector<int> nums2={1,7};
    ListNode* head2=convert(nums2);
    head2->next->next=head->next->next->next;
    head=findInsertion(head1,head2);
    if(head)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}
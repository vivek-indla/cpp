#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode* bottom;
     ListNode() : val(0), next(nullptr),bottom(nullptr){}
     ListNode(int x) : val(x), next(nullptr),bottom(nullptr){}
     ListNode(int x, ListNode *next) : val(x), next(next){}
};
ListNode* convert(vector<int> &nums){
    ListNode* head=new ListNode(nums[0]);
    ListNode* mover=head;
    for(int i=1;i<nums.size();i++){
        ListNode* temp=new ListNode(nums[i]);
        mover->bottom=temp;
        mover=temp;
    }
    return head;
}
void printBottom(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->bottom;
    }
}
ListNode* mergeTwoLists(ListNode* list1,ListNode* list2){
    ListNode* dummyHead=new ListNode(-1);
    ListNode* traverse=dummyHead;
    while(list1 && list2){
        if(list1->val < list2->val){
            traverse->bottom=list1;
            list1=list1->bottom;
        }
        else{
            traverse->bottom=list2;
            list2=list2->bottom;
        }
        traverse=traverse->bottom;
    }
    if(list1) traverse->bottom=list1;
    else traverse->bottom=list2;
    return dummyHead->bottom;
}
ListNode* flatten(ListNode* head){
    if(!head || !head->next){
        return head;
    }
    ListNode* Node=flatten(head->next);
    head=mergeTwoLists(head,Node);
    return head;
}
int main(){
    vector<int> nums1={5,7,8,30};
    vector<int> nums2={10};
    vector<int> nums3={19,22,50};
    vector<int> nums4={28};
    ListNode* list1=convert(nums1);
    ListNode* list2=convert(nums2);
    ListNode* list3=convert(nums3);
    ListNode* list4=convert(nums4);
    list1->next=list2;
    list2->next=list3;
    list3->next=list4;
    ListNode* head=flatten(list1);
    printBottom(head);
    return 0;
}
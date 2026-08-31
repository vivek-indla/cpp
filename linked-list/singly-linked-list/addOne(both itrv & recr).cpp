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
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr){
        ListNode* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
// iterative approach time : O(n) two reversal + one traversal space: O(1) no extra space
// ListNode* addOne(ListNode* head){
//     head=reverseList(head);
//     ListNode* temp=head;
//     int carry=1;
//     while(temp){
//         int sum=temp->val+carry;
//         temp->val=sum%10;
//         carry=sum/10;
//         if(!temp->next && carry){
//             temp->next=new ListNode(carry);
//             carry=0;
//         }
//         temp=temp->next;
//     }
//     return reverseList(head);
// }
// recursive approach time : O(N) space : O(N) for recursion
int addOneLast(ListNode* node){
    if(!node){
        return 1;
    }
    int carry=addOneLast(node->next);
    int sum=carry+node->val;
    node->val=sum%10;
    return sum/10;
}
ListNode* addOne(ListNode* head){
    int carry=addOneLast(head);
    if(carry){
        ListNode* newHead=new ListNode(carry);
        newHead->next=head;
        return newHead;
    }
    return head;
}
int main(){
    vector<int> nums={9,9,9};
    ListNode* head=convert(nums);
    head=addOne(head);
    print(head);
}
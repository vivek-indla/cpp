#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convert(vector<int>& nums){
    Node* head=new Node(nums[0]);
    Node* mover=head;
    for(int i=1;i<nums.size();i++){
        Node* temp=new Node(nums[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
class Solution{
    public:
    Node* rotateList(Node* head,int k){
        if(head==NULL ||head->next==NULL || k==0){
            return head;
        }
        int total=1;
        Node* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
            total++;
        }
        k%=total;
        int pos=total-k;
        tail->next=head;
        Node* temp=head;
        Node* newHead=NULL;
        int count=0;
        while(temp){
            count++;
            if(count==pos){
                newHead=temp->next;
                temp->next=NULL;
                break;
            }
            temp=temp->next;
        }
        return newHead;
    }
};
int main(){
    vector<int> nums={1,2,3,4,5};
    Node* head=convert(nums);
    Solution s1;
    head=s1.rotateList(head,2);
    print(head);
    return 0;
}
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
Node* getKthNode(Node* temp,int k){
    k-=1;
    while(temp!=NULL && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}
Node* reverseList(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}
class Solution{
    public:
    Node* reverseKGroups(Node* head,int k){
        Node* temp=head;
        Node* prevNode=NULL;
        while(temp!=NULL){
            Node* kthNode=getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode)
                    prevNode->next=temp;
                break;
            }
            Node* nextNode=kthNode->next;
            kthNode->next=NULL;
            reverseList(temp);
            if(prevNode==NULL){
                head=kthNode;
            }
            else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};
int main(){
    vector<int> nums={3,5,2,9};
    Node* head=convert(nums);
    Solution s1;
    head=s1.reverseKGroups(head,0);
    print(head);
    return 0;
}
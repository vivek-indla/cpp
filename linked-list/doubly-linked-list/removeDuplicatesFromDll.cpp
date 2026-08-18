#include<bits/stdc++.h>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* prev;
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }

};
Node* convert(vector<int> &nums){
    Node* head=new Node(nums[0]);
    Node* prev=head;
    for(int i=1;i<nums.size();i++){
        Node* temp=new Node(nums[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
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
Node* removeDuplicatesFromDll(Node* head){
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* newNode=temp->next;
        while(newNode!=NULL && newNode->data==temp->data){
            Node* delNode=newNode;
            newNode=newNode->next;
            delete delNode;
        }
        temp->next=newNode;
        if(newNode!=NULL) newNode->prev=temp;

        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> nums={1,1,1,2,3,3,4};
    Node* head=convert(nums);
    head=removeDuplicatesFromDll(head);
    print(head);
}
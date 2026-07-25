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
//Insertion of LinkedList
Node* InsertHead(Node* head,int value){
    if(head==NULL){
        return NULL;
    }
    Node* newHead=new Node(value);
    newHead->next=head;
    head->prev=newHead;
    newHead->prev=nullptr;
    return newHead;
}
Node* InsertTail(Node* head,int value){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return InsertHead(head,value);
    }
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* newTail=new Node(value);
    tail->prev->next=newTail;
    tail->prev=newTail;
    newTail->prev=tail->prev;
    newTail->next=tail;
    return head;
}
Node* InsertK(Node* head,int k,int value){
    if(head==NULL){
        return NULL;
    }    
    if(head->next==NULL){
        return InsertHead(head,value);
    }
    int count=0;
    Node* temp = head;
    while(temp){
        count++;
        if(count==k) break;
        temp=temp->next;
    }
    Node* back=temp->prev;
    Node* newNode=new Node(value,temp,back);
    back->next=newNode;
    temp->prev=newNode;
    return head;
}
void InsertNode(Node* node,int value){
    if(node==NULL){
        return;
    }
    Node* back=node->prev;
    Node* newNode=new Node(value,node,back);
    back->next=newNode;
    node->prev=newNode;
}
int main(){
    vector<int> nums={3,5,2,9};
    Node* head=convert(nums);

    // head=InsertHead(head,8);
    // head=InsertHead(head,10);
    // print(head);
    
    // head=InsertTail(head,8);
    // head=InsertTail(head,10);
    // print(head);
    
    // head=InsertK(head,2,8);
    // head=InsertK(head,5,10);
    // print(head);
    
    InsertNode(head->next->next,10);
    InsertNode(head->next,100);
    print(head);
    
}
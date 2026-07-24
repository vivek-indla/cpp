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
Node* findTail(Node* head){
    Node* temp=head;
    Node* tail;
    while(temp){
        if(temp->next==NULL){
            tail=temp;
            return tail;
        }
        temp=temp->next;
    }
    return head;
}
void printPrev(Node* tail){
    Node* temp=tail;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}
//to verify whether the doubly linked list is working better we need cross
//verify using head traversal and tail traversal
//Deletion of Doubly Linked List
//Deletion at the head
Node* DeleteHead(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* back=head;
    head=head->next;
    head->prev=nullptr;
    back->next=nullptr;
    delete back;
    return head;
}
//Deletion of Tail of the Linkedlist
Node* DeleteTail(Node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* back=head;
    while(back->next->next!=nullptr){
        if(back->next==NULL){
            back->next=nullptr;
            back->next->prev=nullptr;
            return head;
        }
        back=back->next;
    }
    return head;
}

int main(){
    vector<int> nums={3,2,5,9};
    Node* head=convert(nums);
    Node* tail=findTail(head);
    // head=DeleteHead(head);
    // cout<<"head Traversal: ";
    // print(head);
    // cout<<endl;
    // cout<<"Tail Traversal: ";
    // printPrev(tail);
    
    head=DeleteTail(head);
    cout<<"head Traversal: ";
    print(head);
    cout<<endl;
    cout<<"Tail traversal: ";
    printPrev(tail);
}

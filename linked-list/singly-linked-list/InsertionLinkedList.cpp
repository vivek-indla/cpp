#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* convert(vector<int> &nums){
    Node* head=new Node(nums[0]);
    Node* move=head;
    for(int i=1;i<nums.size();i++){
        Node* temp=new Node(nums[i]);
        move->next=temp;
        move=temp;
    }
    return head;
}
void traverse(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    
}
//Insertion in the LinkedList
Node* InsertHead(Node* head,int value){
    Node* temp=new Node(value,head);
    return temp;
}
Node* InsertTail(Node* head,int value){
    if(head==NULL){
        return new Node(value);
    }
    Node* tail=new Node(value,nullptr);
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=tail;
    return head;
}
Node* InsertAtK(Node* head,int k,int value){
    if(head==NULL){
        if(k==1){
            return new Node(value);
        }
        else{
        return head;
        }
    }
    if(k==1){
        Node* temp=new Node(value,head);
        return temp;
    }
    Node* newNode=new Node(value);
    Node* temp=head;
    int count=0;
    while(temp){
        count++;
        if(count==k-1){
           newNode->next=temp->next;
           temp->next=newNode;
           return head;
        }
        temp=temp->next;
    }
    return head;
}
Node* InsertAtValue(Node* head,int value,int k){
    if(head==NULL){
        return head;
    }
    if(head->data==k){
        Node* temp=new Node(value,head);
        return temp;
    }
    Node* newNode=new Node(value);
    Node* temp=head;
    Node* prev=NULL;
    while(temp){
        if(temp->data==k){
            newNode->next=temp;
            prev->next=newNode;
            return head;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int> nums={3,2,5,9,4};
    Node* head=convert(nums);
    // int length=ll_length(head);
    // cout<<length<<endl;
    // int value=4;
    // int found=search(head,value);
    // cout<<found<<endl;
    // return 0;
    //Deletion of linkedlist 
    // head=Deletehead(head);
    // head=DeleteTail(head);
    // traverse(head);
    // head=DeletePosition(head,5);
    // traverse(head);
    // head=removeK(head,5);
    // traverse(head);
    // head=DeleteValue(head,8);
    // traverse(head);
    //Insertion of linkedlist
    // head=InsertHead(head,7);
    // head=InsertHead(head,8);
    // // traverse(head);
    // head=InsertTail(head,8);
    // head=InsertTail(head,7);
    // traverse(head);
    // head=InsertAtK(head,7,1);
    // traverse(head);
    head=InsertAtValue(head,8,8);
    traverse(head);
    
    return 0;
}
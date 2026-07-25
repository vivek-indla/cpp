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
//Deletion of Doubly Linked List
//Deletion at the head
Node* DeleteHead(Node* head) {
    if (head == NULL){
        return NULL;
    }
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
    Node* temp = head;
    head=head->next;
    temp->next=nullptr;
    head->prev=nullptr;
    delete temp;
    return head;
}
//Deletion of Tail of the Linkedlist
Node* DeleteTail(Node* head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* temp=head;
    while(temp){
        if(temp->next->next==nullptr){
            Node* newNode=temp->next;
            newNode->prev=nullptr;
            temp->next=nullptr;
            delete newNode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
// striver bhai approach
Node* deleteTail(Node* head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=temp->prev;
    newNode->next=nullptr;
    temp->prev=nullptr;
    delete temp;
    return head;
}
//it's my approach used to work for every edge case except size of the linked list+1;
// this will be sorted-out soon :)
Node* DeleteK(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        head->prev=nullptr;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=head;
    while(temp){
        count++;
        if(count==k-1){
            Node* newNode=temp->next;
            temp->next=newNode->next;
            newNode->prev=temp;
            newNode->next=nullptr;
            newNode->prev=nullptr;
            delete newNode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
//striver bhai approach
//i have changed to something it the code where the count starts from 1 and if k position only exist in the linkedlist it will continue
// if further it will directly return head and original linked list printed
Node* deleteK(Node* head,int k){
    if(head==NULL){
        return NULL;
    }
    Node* kNode=head;
    int count=1;
    while(kNode!=NULL && count<k){
        count++;
        kNode=kNode->next;
    }
    if(kNode==nullptr){
        return head;
    }
    Node* front=kNode->next;
    Node* back=kNode->prev;
    if(back==NULL && front==NULL){
        return NULL;
    }
    else if(back==NULL){
        return DeleteHead(head);
    }
    else if(front==NULL){
        return deleteTail(head);
    }
    back->next=front;
    front->prev=back;
    kNode->next=nullptr;
    kNode->prev=nullptr;
    delete kNode;
    return head;
}
void DeleteNode(Node* temp){
    Node* back=temp->prev;
    Node* front=temp->next;
    if(front==NULL){
        back->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return; 
    }
    back->next=front;
    front->prev=back;
    temp->next=nullptr;
    temp->prev=nullptr;
    delete temp;
}
int main(){
    vector<int> nums={3,5,2,9};
    Node* head=convert(nums);
    // head=DeleteHead(head);
    // cout<<"head Traversal: ";
    // print(head);
    // cout<<endl;
    
    // head=DeleteTail(head);
    // cout<<"head Traversal: ";
    // print(head);
    // cout<<endl;
    
    // head=deleteK(head,6);
    // cout<<"head Traversal: ";
    // print(head);
    // cout<<endl;
    
    DeleteNode(head->next);
    cout<<"head Traversal: ";
    print(head);
    cout<<endl;
}
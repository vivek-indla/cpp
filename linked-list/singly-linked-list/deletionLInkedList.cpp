
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
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
Node* Deletehead(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
//my approach
Node* DeletePosition(Node* head,int k){
    Node* temp=head;
    if(temp==NULL){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count=0;
    while(temp->next!=nullptr){
        count++;
        if(count==k-1){
            Node* Delete=temp->next;
            temp->next=Delete->next;
            //up we can also write temp->next=temp->next->next;
            delete Delete;
            return head;
        }
        temp=temp->next;
    }
    return head;
}
//striver approach
Node* removeK(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    int count=0;
    while(temp){
        count++;
        if(count==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* DeleteValue(Node* head,int value){
    if(head==NULL){
        return head;
    }
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp){    
        if(temp->data==value){
            prev->next=prev->next->next;
            delete temp;
            break;
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
    // head=Deletehead(head);
    // head=DeleteTail(head);
    // traverse(head);
    // head=DeletePosition(head,5);
    // traverse(head);
    // head=removeK(head,5);
    // traverse(head);
    head=DeleteValue(head,8);
    traverse(head);
}
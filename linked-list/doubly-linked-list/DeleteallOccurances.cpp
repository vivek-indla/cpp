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
Node* DeleteallOcc(Node* head,int k){
    Node* temp=head;
    while(temp){
        Node* nextNode=temp->next;
        if(temp->data==k){
            Node* prevNode=temp->prev;
            if(prevNode) prevNode->next=nextNode;
            else head=nextNode;
            if(nextNode) nextNode->prev=prevNode;
            delete temp;
        }
        temp=nextNode;
    }
    return head;
}
int main(){
    vector<int> nums={1,1,2,3,1,5,6,1,5};
    Node* head=convert(nums);
    head=DeleteallOcc(head,5);
    print(head);
}
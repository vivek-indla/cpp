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
Node* convert(vector<int> nums){
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
Node* createLoop(Node* head){
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    // tail->next=head;
    return head;
}
bool DetectLoop(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}
int main(){
    vector<int> nums={3,5,2,9,8,2,4,};
    Node* head=convert(nums);
    head=createLoop(head);
    bool ans=DetectLoop(head);
    if(ans){
    cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}
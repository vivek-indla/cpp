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
//this is brute force approach used to reverse doubly linked list
// time complexity is : O(2N)
// space complexity is: O(N) for using external space stack
Node* BruteForce(Node* head){
    stack<int> st;
    Node* temp=head;
    while(temp){
        st.push(temp->data);
        temp=temp->next;;
    }
    temp=head;
    while(temp){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}
Node* Optimal(Node* head){
    Node* current=head;
    Node* last=NULL;
    while(current){
        last=current->prev;
        current->prev=current->next;
        current->next=last;
        current=current->prev;
    }
    return last->prev;
}
int main(){
    vector<int> nums={3,2,5,9};
    Node* head=convert(nums);
    head=Optimal(head);
    print(head);
}
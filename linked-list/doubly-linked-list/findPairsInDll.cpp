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
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    return tail;
}
vector<pair<int,int>> findPairs(Node* head,int target){
    vector<pair<int,int>> ans;
    Node* left=head;
    Node* right=findTail(head);
    while(left->data < right->data){
        if(left->data + right->data==target){
            ans.push_back({left->data,right->data});
            left=left->next;
            right=right->prev; 
        }
        else if(left->data + right->data < target){
            left=left->next;
        }
        else{
            right=right->prev;
        }
    }
    return ans;
}
int main(){
    vector<int> nums={1,2,3,4,9};
    Node* head=convert(nums);
    vector<pair<int,int>>result= findPairs(head,5);
    for(auto p:result){
        cout<<p.first<<" "<<p.second<<endl;
    }
}
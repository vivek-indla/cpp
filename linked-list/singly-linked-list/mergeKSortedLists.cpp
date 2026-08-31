#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* convert(vector<int> &nums){
    ListNode* head=new ListNode(nums[0]);
    ListNode* mover=head;
    for(int i=1;i<nums.size();i++){
        ListNode* temp=new ListNode(nums[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void print(ListNode* head){
    ListNode* temp=head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
// below is the brute force approach time: O(NlogN) because of sorting and space : O(N) because storing elements and also for storing converting nums into linkedlist
// ListNode* mergeKLists(vector<ListNode*> lists){
//     vector<int> nums;
//     for(auto list:lists){
//         while(list){
//             nums.push_back(list->val);
//             list=list->next;
//     }
//     }
//     sort(nums.begin(),nums.end());
//     return convert(nums);
// }

// optimal approach by using priority queue
ListNode* mergeKLists(vector<ListNode*> lists){
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
    ListNode* dummyHead=new ListNode(-1);
    ListNode* temp=dummyHead;
    for(int i=0;i<lists.size();i++){
        if(lists[i]){
            pq.push({lists[i]->val,lists[i]});
        }
    }
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->val,it.second->next});
        }
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyHead->next;
    }
int main(){
    ListNode* a=new ListNode(1);
    a->next=new ListNode(4);
    a->next->next=new ListNode(5);
    ListNode* b=new ListNode(1);
    b->next=new ListNode(3);
    b->next->next=new ListNode(4);
    ListNode* c=new ListNode(2);
    c->next=new ListNode(6);
    vector<ListNode*> lists={a,b,c};
    ListNode* head=mergeKLists(lists);
    print(head);
}
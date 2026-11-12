#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};
void rcspreOrderTraversal(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    rcspreOrderTraversal(root->left);
    rcspreOrderTraversal(root->right);
}
void itrpreOrderTraversal(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);
        cout<<node->val<<" ";
    }
}
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(7);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->left->right->left=new TreeNode(5);
    root->left->right->right=new TreeNode(6);
    rcspreOrderTraversal(root);
    cout<<endl;
    itrpreOrderTraversal(root);
    return 0;
}
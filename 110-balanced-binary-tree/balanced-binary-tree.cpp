/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int heightoftree(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int op1=heightoftree(root->left);
    int op2=heightoftree(root->right);
    if(abs(op1-op2)>1) return -1;
    if(op1==-1 || op2== -1){
        return -1;
    }
    int ans=max(op1,op2)+1;
    return ans;

}
bool isBalanced(TreeNode* root){
    if(root==NULL) return true;
    int h=heightoftree(root);
    if(h==-1) return false;
    return true;
}
};
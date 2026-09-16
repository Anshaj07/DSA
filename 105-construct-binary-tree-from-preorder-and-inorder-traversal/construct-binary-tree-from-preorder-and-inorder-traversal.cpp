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
    int findPosition(vector<int>& inorder ,int target){
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==target){return i;}
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int& index){
        if(index>=preorder.size() || start>end) return NULL;
        TreeNode* root=new TreeNode(preorder[index]);
        int pos = findPosition(inorder,preorder[index]);
        index++;
        root->left = solve(preorder , inorder , start , pos-1 , index );
        root->right = solve(preorder,inorder,pos+1,end,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int inorderStart = 0;
    int inorderEnd = inorder.size()-1;
    int preorderIndex=0;
    TreeNode* ans = solve(preorder,inorder,inorderStart,inorderEnd,preorderIndex);
    return ans;
    }
};
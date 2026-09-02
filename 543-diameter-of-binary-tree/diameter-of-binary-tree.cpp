class Solution {
public:
    int diameter = 0;

    int height(TreeNode* root){
        if(!root) return 0;

        int op1 = height(root->left);
        int op2 = height(root->right);

        diameter = max(diameter, op1 + op2);

        return 1 + max(op1, op2);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};
class Solution {
public:

    int solve(TreeNode* root, int& ans){
        if(!root) return 0;

        int leftsum = max(0, solve(root->left, ans));
        int rightsum = max(0, solve(root->right, ans));

        ans = max(ans, root->val + leftsum + rightsum);

        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {
        int ans = -1e9;
        solve(root, ans);
        return ans;
    }
};
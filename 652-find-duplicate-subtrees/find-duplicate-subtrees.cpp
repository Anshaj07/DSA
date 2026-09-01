class Solution {
public:

    unordered_map<string, int> mp;
    vector<TreeNode*> ans;

    string solve(TreeNode* root) {

        if (root == NULL) {
            return "#";
        }

        string left = solve(root->left);
        string right = solve(root->right);

        string curr = to_string(root->val) + "," + left + "," + right;

        mp[curr]++;

        if (mp[curr] == 2) {
            ans.push_back(root);
        }

        return curr;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

        solve(root);

        return ans;
    }
};

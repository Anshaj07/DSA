class Solution {
public:

    void MarkParent(TreeNode* root,
                    unordered_map<TreeNode*, TreeNode*>& parent) {

        if (!root) return;

        if (root->left) {
            parent[root->left] = root;
            MarkParent(root->left, parent);
        }

        if (root->right) {
            parent[root->right] = root;
            MarkParent(root->right, parent);
        }
    }

    TreeNode* FindStart(TreeNode* root, int start) {

        if (!root) return NULL;

        if (root->val == start)
            return root;

        TreeNode* left = FindStart(root->left, start);

        if (left) return left;

        return FindStart(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*, TreeNode*> parent;
        MarkParent(root, parent);

        unordered_map<TreeNode*, bool> visited;

        TreeNode* Start = FindStart(root, start);

        queue<TreeNode*> q;
        q.push(Start);
        visited[Start] = true;

        int ans = -1;

        while (!q.empty()) {

            int size = q.size();

            for (int i = 0; i < size; i++) {

                TreeNode* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    visited[front->left] = true;
                    q.push(front->left);
                }

                if (front->right && !visited[front->right]) {
                    visited[front->right] = true;
                    q.push(front->right);
                }

                if (parent.count(front) &&
                    !visited[parent[front]]) {

                    visited[parent[front]] = true;
                    q.push(parent[front]);
                }
            }

            ans++;
        }

        return ans;
    }
};
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool normal = true;
        while(!q.empty()){
            int size=q.size();
            vector<int> level(size,0);
            if(normal){
                for(int i=0;i<size;i++){
                    TreeNode* front = q.front();
                    q.pop();
                    level[i]=front->val;
                    if(front->left) q.push(front->left);
                    if(front->right) q.push(front->right);

                    
                }
                normal=false;
                
            }
            else{
                for(int i=size-1;i>=0;i--){
                    TreeNode* front= q.front();
                    q.pop();
                    level[i]=front->val;
                    if(front->left) q.push(front->left);
                    if(front->right) q.push(front->right);
                }
                normal=true;
            }
            ans.push_back(level);
            
        }
        return ans;
    }
};
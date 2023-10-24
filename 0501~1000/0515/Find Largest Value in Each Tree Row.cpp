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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size(), mx = q.front()->val;
            for(int i = 0;i < n;i ++){
                TreeNode* now = q.front();
                q.pop();
                mx = max(mx, now->val);
                if(now->left)
                    q.push(now->left);
                if(now->right)
                    q.push(now->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

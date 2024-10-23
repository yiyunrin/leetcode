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
    TreeNode* replaceValueInTree(TreeNode* root) {
        int sum = 0, next_sum = 0;
        unordered_map<TreeNode*, int> parent, next_parent;
        queue<pair<TreeNode*, TreeNode*>> q;
        parent[nullptr] = 0;
        q.push({root, nullptr});
        while(!q.empty()){
            int n = q.size();
            while(n --){
                auto [now, par] = q.front();
                q.pop();
                now->val = sum - parent[par];
                if(now->left){
                    next_parent[now] += now->left->val;
                    next_sum += now->left->val;
                    q.push({now->left, now});
                }
                if(now->right){
                    next_parent[now] += now->right->val;
                    next_sum += now->right->val;
                    q.push({now->right, now});
                }
            }
            parent = next_parent;
            sum = next_sum;
            next_parent.clear();
            next_sum = 0;
        }
        return root;
    }
};

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
    int averageOfSubtree(TreeNode* root) {
        cnt = 0;
        dfs(root);
        return cnt;
    }
private:
    int cnt;
    pair<int, int> dfs(TreeNode *root){
        if(root == NULL)
            return {0, 0};
        pair<int, int> l = dfs(root->left), r = dfs(root->right);
        int num = l.second + r.second + 1, sum = l.first + r.first + root->val;
        if(root->val == sum / num)
            cnt ++;
        return {sum, num};
    }
};

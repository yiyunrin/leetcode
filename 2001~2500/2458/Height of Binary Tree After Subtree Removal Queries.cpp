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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        n = 0;
        compute_height(root, 0);
        vector<int> pre_ans(n + 1);
        for(auto [level, pq]: mp){
            auto [mx, value] = pq.top();
            pq.pop();
            if(pq.empty())
                pre_ans[value] = level - 1;
            else
                pre_ans[value] = pq.top().first + level - 1;
            while(!pq.empty()){
                int val = pq.top().second;
                pq.pop();
                pre_ans[val] = mx + level - 1;
            }
        }
        vector<int> ans(queries.size());
        for(int i = 0;i < queries.size();i ++)
            ans[i] = pre_ans[queries[i]];
        return ans;
    }
private:
    // map<level, pq<height, value>> 
    map<int, priority_queue<pair<int, int>>> mp;
    int n;
    int compute_height(TreeNode *root, int level){
        if(root == nullptr)
            return 0;
        n ++;
        int height = max(compute_height(root->left, level + 1), compute_height(root->right, level + 1)) + 1;
        mp[level].push({height, root->val});
        return height;
    }
};

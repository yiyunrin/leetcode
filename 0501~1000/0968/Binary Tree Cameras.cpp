// 參考代碼隨想錄
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
    int minCameraCover(TreeNode* root) {
        re = 0;
        if(camera(root) == 0)
            re ++;
        return re;
    }
private:
    int re;
    // 0: 沒有被camera覆蓋
    // 1: 有camera
    // 2: 有被camera覆蓋
    int camera(TreeNode *root){
        if(root == NULL)
            return 2;
        int left = camera(root->left);
        int right = camera(root->right);
        if(left == 0 || right == 0){
            re ++;
            return 1;
        }
        if(left == 1 || right == 1)
            return 2;
        return 0;
    }
};

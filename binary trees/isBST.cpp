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
    bool dfs(TreeNode* root, double leftBound, double rightBound){
        if(root->val <= leftBound) return false;
        if(root->val >= rightBound) return false;
        bool ans=true;
        if(root->left != nullptr){
            ans = ans &&  dfs(root->left,leftBound, root->val);
            ans = ans && root->val > root->left->val;
        }
        if(root->right != nullptr){
            ans = ans &&  dfs(root->right, root->val, rightBound);
            ans = ans && root->val < root->right->val;
        }
        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};

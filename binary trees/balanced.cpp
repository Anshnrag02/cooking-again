
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
    bool ans = true;

    int f(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = 0, rh = 0;
        if (root->left != nullptr) lh = 1+f(root->left);
        if (root->right != nullptr) rh = 1+f(root->right);

        ans = ans && (abs(lh-rh)>=-1 and abs(lh-rh)<=1);
        return max(lh,rh);
    }
    
    bool isBalanced(TreeNode* root) {
        f(root);
        return ans;
    }
};

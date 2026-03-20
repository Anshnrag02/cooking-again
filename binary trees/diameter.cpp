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
    int ans = 0;

    int f(TreeNode* root){
        if(root==nullptr) return 0;
        int lmax = 0 , rmax = 0;
        if(root->left !=nullptr)
            lmax=f(root->left) + 1;
        if(root->right !=nullptr)
            rmax=f(root->right) + 1;
        ans = max(ans, lmax + rmax);
        return max(lmax,rmax);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int temp = f(root);
        return max(ans,temp);    
    }
};

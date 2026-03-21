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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr) return nullptr;
        if(root==q || root==p) return root;
        TreeNode* sl = nullptr;
        if(root->left!=nullptr and (p->val < root->val || q->val < root->val)) {
            sl=lowestCommonAncestor(root->left,p,q);
        }
        TreeNode* sr = nullptr;
        if(root->right!=nullptr and (p->val > root->val || q->val > root->val)) {
            sr=lowestCommonAncestor(root->right,p,q);
        }
        if(sr!=nullptr and sl!=nullptr) return root;
        if(sl!=nullptr) return sl;
        return sr; 
    }
};

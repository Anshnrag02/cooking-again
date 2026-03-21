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
    int goodNodes(TreeNode* root, int heighestsofar=-1000) {
        if(root==nullptr) return 0;
        bool check = root->val >= heighestsofar;
        int left = goodNodes(root->left, check ? root->val : heighestsofar);
        int right = goodNodes(root->right, check ? root->val : heighestsofar);

        return left + right + check;

    }
};

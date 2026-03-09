class Solution {
public:
    unordered_map<TreeNode*,int>mp;    

    int rob(TreeNode* root) {
        if(mp.count(root)) return mp[root];
        if(root==nullptr) return 0;
        int val = 0;
        if(root->left!=nullptr){
            val+=rob(root->left->left)+ rob(root->left->right);
        }
        if(root->right!=nullptr){
            val+=rob(root->right->left)+ rob(root->right->right);
        }
        return mp[root] = max(val + root->val, rob(root->left)+rob(root->right));
    }
};
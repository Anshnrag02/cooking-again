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
    vector<vector<int>>ans;


    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        vector<vector<int>>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){ 
            auto [node, height] = q.front();q.pop();
            if(node->left != nullptr) q.push({node->left,height+1});
            if(node->right != nullptr) q.push({node->right,height+1});
            if(ans.size()==height) ans.push_back({});
            ans[height].push_back(node->val);
        }
        return ans;
    }
};

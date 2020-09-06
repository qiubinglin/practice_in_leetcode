
方法1
c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        predfs(root, ans);
        return ans;
    }
    
    void predfs(TreeNode* root, vector<int> &ans){
        if(!root) return;
        ans.push_back(root->val);
        predfs(root->left, ans);
        predfs(root->right, ans);
    }
};
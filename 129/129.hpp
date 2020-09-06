
方法1
深度搜索算法
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
    int sum;
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if(root)
            dfs(root, 0);
        return sum;
    }
    
    void dfs(TreeNode *root, int part){
        part *= 10;
        part += root->val;
        if(!root->left && !root->right) sum += part;
        if(root->left)
            dfs(root->left, part);
        if(root->right)
            dfs(root->right, part);
    }
};
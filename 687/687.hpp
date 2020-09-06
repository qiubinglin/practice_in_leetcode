687.最长等值路径
找到树中的最长路径大小，路径中结点的值都相等

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
    int longestUnivaluePath(TreeNode* root) {
        if(!root){
            return 0;
        }
        int res = 0;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode *node, int &res){
        int l = node->left ? dfs(node->left, res) : 0;
        int r = node->right ? dfs(node->right, res) : 0;
        
        if(node->left){
            l = (node->val == node->left->val) ? l+1 : 0; //当前结点与左结点相连
        }
        if(node->right){
            r = (node->val == node->right->val) ? r+1 : 0;
        }
        res = max(res, l+r); //l+r为当前结点可连接的最长路径大小
        return max(l, r); //返回以当前结点为端点的最长路径大小
    }
};
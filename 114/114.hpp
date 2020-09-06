
方法1
从根节点开始以左子树的右斜链表对齐自身右斜链表，将左子树并入右子树中。
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
    void flatten(TreeNode* root) {
        while(root){
            if(root->left && root->right){
                TreeNode *tmp = root->left;
                while(tmp->right) tmp = tmp->right;
                tmp->right = root->right;
            }
            
            if(root->left) root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
    }
};
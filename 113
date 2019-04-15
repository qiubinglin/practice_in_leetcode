
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
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> part_ans;
        dfs(root, sum, part_ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int sum, vector<int> part_ans){
        if(root == NULL) return;
        
        sum -= root->val;
        part_ans.push_back(root->val);
        if(sum == 0 && !root->left && !root->right){
            ans.push_back(part_ans);
        }
        else{
            dfs(root->left, sum, part_ans);
            dfs(root->right, sum, part_ans);
        }
    }
};
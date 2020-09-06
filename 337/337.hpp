
方法1：
动态规划

c++
class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return tryRob(root, l, r);
    }
    
    int tryRob(TreeNode *root, int &l, int &r){
        if(!root) return 0;
        
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        
        return max(root->val+ll+lr+rl+rr, l+r);
    }
};

方法1：
c++
(from victorlee)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *l = root, *r = root;
        int h1 = 1, h2 = 1;
        while(l->left){
            l = l->left;
            ++h1;
        }
        while(r->right){
            r = r->right;
            ++h2;
        }
        if(h1 == h2) return pow(2,h1)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};
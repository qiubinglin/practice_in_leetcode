
方法1：
使用stack实现中序遍历
c++
(from aweyiun)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode *node = root;
        while(node || !st.empty()){
            while(node){
                st.push(node);
                node = node->left;
            }
            
            node = st.top();
            st.pop();
            if(--k == 0){
                break;
            }
            node = node->right;
        }
        return node->val;
    }
};
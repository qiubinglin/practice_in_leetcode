
方法1：
c++
(from StefanPochmann)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *visitor;
    stack<TreeNode*> st; 
    
public:
    
    BSTIterator(TreeNode* root) {
        visitor = root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(visitor){
            st.push(visitor);
            visitor = visitor->left;
        }
        TreeNode *next = st.top();
        st.pop();
        visitor = next->right;
        return next->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return visitor != NULL || !st.empty();
    }
};
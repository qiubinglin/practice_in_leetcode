
方法1
深度搜索算法
c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        horizon_connect(root);
        return root;
    }
    
    void horizon_connect(Node *root){
        if(!root) return;
        
        if(root->left){
            root->left->next = root->right;
            root->right->next = NULL;
            if(root->next){
                root->right->next = root->next->left;
            }
        }
        horizon_connect(root->left);
        horizon_connect(root->right);
    }
};
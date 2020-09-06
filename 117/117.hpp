
方法1
广度搜索算法
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
        Node *now, *head, *tail;
        now = root;
        head = tail = NULL;
        
        while(now){
            if(now->left){
                if(tail) tail = tail->next = now->left;
                else head = tail = now->left;
            }
            if(now->right){
                if(tail) tail = tail->next = now->right;
                else head = tail = now->right;
            }
            if(!(now = now->next)){
                now = head;
                head = tail = NULL;
            }
        }
        return root; 
    }
};
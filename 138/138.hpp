
方法1:
深度搜索算法
c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> isCopy;
        return copy(head, isCopy);
    }
    
    Node* copy(Node *node, unordered_map<Node*, Node*> &isCopy){
        if(!node) return NULL;
        
        Node *nNode = NULL;
        if(isCopy.find(node) != isCopy.end()){
            nNode = isCopy[node];
        }
        else{
            nNode = new Node();
            nNode->val = node->val;
            isCopy.insert({node, nNode});
            nNode->next = copy(node->next, isCopy);
            nNode->random = copy(node->random, isCopy);
        }
        return nNode;
    }
};
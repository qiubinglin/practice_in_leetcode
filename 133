
方法1：
深度搜索算法
c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> isCreated;
        return clone(isCreated, node);
    }
    
    Node* clone(unordered_map<Node*, Node*> &isCreated, Node *node){
        Node *c = NULL;
        if(isCreated.find(node) != isCreated.end()){
            c = isCreated[node];
        }
        else{
            c = new Node();
            c->val = node->val;
            isCreated.insert({node, c});
            for(auto pNode : node->neighbors){
                c->neighbors.push_back(clone(isCreated, pNode));
            }
        }
        return c;
    }
};
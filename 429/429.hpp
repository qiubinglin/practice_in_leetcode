429.结点树分层输出
结点同一辈分即为同一层

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root){
            return res;
        }
        queue<Node*> nq;
        int curCount = 1, nextCount = 0; //记录当前行和下一行的结点个数
        nq.push(root);
        res.push_back({});
        
        //bfs
        while(!nq.empty()){
            Node *node = nq.front();
            nq.pop();
            
            auto &cr = node->children;
            for(int i = 0; i < cr.size(); ++i){
                nq.push(cr[i]);
                ++nextCount;
            }
            res.back().push_back(node->val);
            
            --curCount;
            if(curCount == 0 && !nq.empty()){ //当前行结点遍历结束
                res.push_back({}); //准备添加下一行的结点
                curCount = nextCount; //更新当前行和下一行的记录值
                nextCount = 0;
            }
        }
        return res;
    }
};
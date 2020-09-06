
方法1：
逐层去掉叶结点
c++
class Solution {
public:
    struct Node{
        unordered_set<int> neighbor;
        bool isLeaf(){ return neighbor.size() == 1;};
    };
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> buffer1, buffer2;
        vector<int> *pB1 = &buffer1, *pB2 = &buffer2;
        
        if(n == 1){
            buffer1.push_back(0);
            return buffer1;
        }
        if(n == 2){
            buffer1.push_back(0);
            buffer1.push_back(1);
            return buffer1;
        }
        
        //建立图
        vector<Node> graph(n);
        for(auto &e : edges){
            graph[e[0]].neighbor.insert(e[1]);
            graph[e[1]].neighbor.insert(e[0]);
        }
        
        //找到所有叶结点
        for(int i = 0; i < n; ++i){
            if(graph[i].isLeaf()) pB1->push_back(i);
        }
        
        //逐层去掉叶结点
        while(1){
            for(int &i : *pB1){
                for(auto &nei : graph[i].neighbor){
                    graph[nei].neighbor.erase(i);
                    if(graph[nei].isLeaf()) pB2->push_back(nei);
                }
            }
            
            if(pB2->empty()) return *pB1;
            
            pB1->clear();
            swap(pB1, pB2);
        }
    }
};
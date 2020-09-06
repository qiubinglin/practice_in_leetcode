
方法1
dfs实现有向图的拓扑排序
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        
        vector<bool> todo(numCourses, false), done(numCourses, false);
        vector<int> order;
        
        for(int i = 0; i < numCourses; ++i){
            if(!dfs(i, g, todo, done, order)){
                order.clear();
                return order;
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
    
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<vector<int>>& prerequisites){
        graph g(numCourses);
        for(auto &p : prerequisites){
            g[p[1]].push_back(p[0]);
        }
        return g;
    }
    
    bool dfs(int i, graph &g, vector<bool> &todo, vector<bool> &done, vector<int> &order){
        if(todo[i]){
            return false;
        }
        if(done[i]){
            return true;
        }

        todo[i] = done[i] = true;
        
        for(auto &v : g[i]){
            if(!dfs(v, g, todo, done, order)){
                return false;
            }
        }
        todo[i] = false;
        order.push_back(i);
        return true;
    }
};
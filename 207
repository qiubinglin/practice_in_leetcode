
该题考察的是拓扑排序

方法1：
广度搜索算法
c++
(from jianchao-li)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeDegrees(numCourses, g);
        
        for(int i = 0; i < numCourses; ++i){
            int j = 0;
            for(; j < numCourses; ++j){
                if(!degrees[j]) break;
            }
            
            if(j == numCourses) return false;
            
            --degrees[j];
            for(auto &k : g[j]){
                --degrees[k];
            }
        }
        return true;
    }
    
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites){
        graph g = graph(numCourses);
        for(auto &p : prerequisites){
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeDegrees(int numCourses, graph &g){
        vector<int> degrees(numCourses);
        for(auto &elm : g){
            for(auto &i : elm){
                ++degrees[i];
            }
        }
        return degrees;
    }
};

方法2：
深度搜索算法
c++
(from jianchao-li)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> todo(numCourses, false), done(numCourses, false);
        graph g = buildGraph(numCourses, prerequisites);
        
        for(int i = 0; i < numCourses; ++i){
            if(!done[i] && !dfs(todo, done, g, i)){
                return false;
            }
        }
        return true;
    }
    
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites){
        graph g = graph(numCourses);
        for(auto &p : prerequisites){
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool dfs(vector<bool> &todo, vector<bool> &done, graph &g, int i){
        if(todo[i]) return false;
        if(done[i]) return true;
        
        todo[i] = done[i] = true;
        for(auto &n : g[i]){
            if(!dfs(todo, done, g, n)){
                return false;
            }
        }
        todo[i] = false;
        
        return true;
    }
};
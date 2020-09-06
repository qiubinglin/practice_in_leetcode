
方法1：
此题为求取欧拉路径，可以用Hierholzer's algorithm

c++
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        buildGraph(tickets);
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> ans;
    
    void buildGraph(vector<vector<string>>& tickets){
        for(auto &edge : tickets){
            graph[edge[0]].push(edge[1]);
        }
    }
    
    void dfs(string f_vtex){
        auto &t_vtexs = graph[f_vtex];
        
        while(!t_vtexs.empty()){
            string vtex = t_vtexs.top();
            t_vtexs.pop();
            dfs(vtex);
        }
        ans.push_back(f_vtex);
    }
};
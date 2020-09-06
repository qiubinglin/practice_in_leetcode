
方法1：
dfs加回溯
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> part;
        getCombination(ans, part, k, n, 1);
        return ans;
    }
    
    void getCombination(vector<vector<int>> &ans, vector<int> &part, int k, int n, int beg){
        if(k == 0 && n == 0){
            ans.push_back(part);
        }
        if(k <= 0 || n < 0){
            return;
        }
        for(int i = beg; i <= 9; ++i){
            part.push_back(i);
            getCombination(ans, part, k-1, n-i, i+1);
            part.pop_back();
        }
    }
};

方法1：
广度搜索算法

c++
(from jianchao-li)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, offsets[] = {0, 1, 0, -1, 0};
        int island = 0;
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    ++island;
                    queue<pair<int, int>> qe;
                    qe.push({i, j});
                    grid[i][j] = '.';
                    while(!qe.empty()){
                        pair p = qe.front();
                        qe.pop();
                        for(int k = 0; k < 4; ++k){
                            int r = p.first + offsets[k], c = p.second + offsets[k+1];
                            if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1'){
                                qe.push({r, c});
                                grid[r][c] = '.';
                            }
                        }
                    }
                }
            }
        }
        return island;
    }
};
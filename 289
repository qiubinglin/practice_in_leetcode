
方法1：

c++
(from morrischen2008)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                //检查相邻的未处理格
                check(board, i, j, i, j+1);
                check(board, i, j, i+1, j-1);
                check(board, i, j, i+1, j);
                check(board, i, j, i+1, j+1);
                
                //写入当前格的新状态值
                if(board[i][j] >= 5 && board[i][j] <= 7) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
    
    void check(vector<vector<int>> &board, int i, int j, int a, int b){
        int m = board.size(), n = board[0].size();
        if(a >= m || b >= n || b < 0) return;
        
        //考虑到两个格的值会互相影响，所以对当前处理格和未处理格都进行了处理。以取余的方式保证了正确判断某格的原始值是0还是1.
        if(board[i][j]%2) board[a][b] += 2;
        if(board[a][b]%2) board[i][j] += 2;
    }
};
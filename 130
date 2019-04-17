
方法1：
1、首先找出位于边界的'O'，将它以及和它相邻的'O'都变为'1'
2、遍历二维数组将'O'变为'X'
3、遍历二维数组将'1'变为'O'
c++
(from sugeladi)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(!row) return;
        int col = board[0].size();
        
        for(int i = 0; i < row; ++i){
            check(board, i, 0, row, col);
            if(col > 1)
                check(board, i, col-1, row, col);
        }
        
        for(int j = 0; j < col; ++j){
            check(board, 0, j, row, col);
            if(row > 1)
                check(board, row-1, j, row, col);
        }
        
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
            }
        
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j){
                if(board[i][j] == '1') board[i][j] = 'O';
            }
    }
    
    void check(vector<vector<char>> &board, int i, int j, int row, int col){
        if(board[i][j] == 'O'){
            board[i][j] = '1';
            if(i > 1)
                check(board, i-1, j, row, col);
            if(j > 1)
                check(board, i, j-1, row, col);
            if(i+1 < row)
                check(board, i+1, j, row, col);
            if(j+1 < col)
                check(board, i, j+1, row, col);
        }
    }
};
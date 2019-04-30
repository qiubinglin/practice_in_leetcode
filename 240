
方法1：
从左下角开始
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rlen = matrix.size();
        int clen = rlen ? matrix[0].size() : 0;
        if(rlen == 0 || clen == 0) return false;
        int i = rlen-1, j = 0;
        
        while(1){
            if(matrix[i][j] == target) return true;
            
            if(target < matrix[i][j] && i > 0) --i;
            else if(target > matrix[i][j] && j < clen-1) ++j;
            else break;
        }
        return false;
    }
};
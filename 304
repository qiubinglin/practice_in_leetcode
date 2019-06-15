
方法1：

c++
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            isEmpty = true;
            return;
        }
        int m = matrix.size(), n = matrix[0].size();
        rectSum.resize(m+1, vector<int>(n+1, 0));
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                rectSum[i][j] = rectSum[i-1][j] + rectSum[i][j-1] - rectSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        isEmpty = false;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(isEmpty) return 0;
        return rectSum[row2+1][col2+1] - rectSum[row1][col2+1] - rectSum[row2+1][col1] + rectSum[row1][col1];
    }
    
private:
    vector<vector<int>> rectSum;
    bool isEmpty;
};

方法1：
动态规划
c++
(from zhukov)
class Solution {
public:
    int numSquares(int n) {
        if(n <= 0) return 0;
        
        vector<int> cntOfNumSquares({0});
        
        while(cntOfNumSquares.size() <= n){
            int numSqua = INT_MAX;
            int m = cntOfNumSquares.size();
            //cntOfNumSquares[m]的值等于cntOfNumSquares[m-i*i]的值加上1
            for(int i = 1; i*i <= m; ++i){
                numSqua = min(numSqua, cntOfNumSquares[m-i*i]+1);
            }
            cntOfNumSquares.push_back(numSqua);
        }
        return cntOfNumSquares.back();
    }
};
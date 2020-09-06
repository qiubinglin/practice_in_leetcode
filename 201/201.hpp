
方法1
匹配以最高位为起点的最长相同位序列。结果即为此值

c++
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == n) return m;
        int i = 30;
        int ans = 0;
        while(i){
            int a = m>>i, b = n>>i;
            if(a != b) break;
            ans = a;
            --i;
        }
        return ans<<(i+1);
    }
};

方法1：
只有因子数为奇数个的灯会亮着，而因子数为奇数个的数为完全平方数。

c++
class Solution {
public:
    int bulbSwitch(int n) {
        int counts = 0;

        //找到所有的完全平方数
        for (int i=1; i*i<=n; ++i) {
            ++ counts;    
        }

        return counts;
    }
};
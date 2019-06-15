方法1：
对于满足条件的z有z = m*x + n*y，m和n是整数或0。可以得出z总是被x和y的最大公约数整除。

c++
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (z - x <= y && z % gcd(x, y) == 0);
    }
private:
    int gcd(int x, int y)
    {
        return y == 0 ? x : gcd(y, x % y);
    }
};

方法1
python
class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        nth = 0;
        while n > 1:
            nth += 1
            if n%2 == 0:
                n = n/2
            //此解法的关键在于+1还是-1的判断，判断的逻辑是选择包含两个以上2因子的偶数进行变换
            elif n%4 == 1 or n == 3: //此情况下选择-1则包含两个以上2因子，+1则仅有一个2因子
                n -= 1
            elif n%4 == 3: //同理
                n += 1
        return nth

方法2
自顶向下带备忘录的动态规划
c++
class Solution {
private:
    unordered_map<int, int> num_map;
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(num_map.find(n) == num_map.end()){
            if(n%2 == 0){
                num_map[n] = integerReplacement(n/2) + 1;
            }
            else{
                num_map[n] = min(integerReplacement(n/2), integerReplacement(n/2+1)) + 2;
            }
        }
        return num_map[n];
    }
};
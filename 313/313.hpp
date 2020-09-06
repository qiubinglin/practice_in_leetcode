
方法1：

c++
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        //ugly中的每一个数都由primes中的元素乘上该数之前的某数得到。
        vector<int> index(len, 0), ugly(n, INT_MAX);
        ugly[0] = 1;
        
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < len; ++j) ugly[i] = min(ugly[i], ugly[index[j]]*primes[j]);//ugly[index[j]]*primes[j]是现阶段primes[i]可以得出的最小的ugly数。
            for(int j = 0; j < len; ++j) index[j] += (ugly[i] == ugly[index[j]]*primes[j]);//ugly[index[j]]*primes[j]已填入，所以将index[i]+1
        }
        return ugly[n-1];
    }
};
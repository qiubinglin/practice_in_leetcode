
方法1：

c++
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1, 0);
        
        if(num == 0) return ans;
        ans[1] = 1;
        if(num == 1) return ans;
        
        int len = 2;
        while(len < num+1){
            int nowlen = len;
            while(nowlen < 2*len){
                ans[nowlen] = ans[nowlen-len]+1;
                ++nowlen;
                if(nowlen > num){
                    break;
                }
            }
            len = nowlen;
        }
        return ans;
    }
};
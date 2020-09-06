
方法1：
使用bit来记录信息

c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maxLen;
        int ans = 0;
        for(auto &str : words){
            int mask = 0;
            for(char &c : str){
                mask |= 1 << (c-'a');
            }
            maxLen[mask] = max(maxLen[mask], (int)str.size());
            for(auto &elm : maxLen){
                if(!(mask & elm.first)){
                    ans = max(ans, (int)str.size()*elm.second);
                }
            }
        }
        return ans;
    }
};
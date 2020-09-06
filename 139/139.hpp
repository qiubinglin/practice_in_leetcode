
方法1
动态规划算法
c++
(from paul7)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return false;
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); ++i){
            for(int j = i-1; j >= 0; --j){
                if(dp[j]){
                    string tmp = s.substr(j, i-j);
                    if(words.find(tmp) != words.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
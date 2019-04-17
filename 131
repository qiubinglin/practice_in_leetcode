
方法1
深度搜索算法，回溯法。具体实施就是，先找第一个回文子串的所有可能，再找第二个子串的所有可能。。。直至末尾，就像一课派生树
c++
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partans;
        if(s.empty()) return ans;
        
        make_partition(s, ans, partans, 0);
        return ans;
    }
    
    void make_partition(string &s, vector<vector<string>> &ans, vector<string> &part, int start){
        if(start == s.size()){
            ans.push_back(part);
            return;
        }
        
        for(int len = 1; start + len <= s.size(); ++len){
            string tmp = s.substr(start, len);
            if(isPalindrome(tmp)){
                part.push_back(tmp);
                make_partition(s, ans, part, start+len);
                part.pop_back();
            }
        }
    }
    
    bool isPalindrome(string tmp){
        int left = 0, right = tmp.size()-1;
        while(left <= right){
            if(tmp[left++] != tmp[right--]) return false;
        }
        return true;
    }
};

方法1：
c++:
class Solution {
public:
    string reverseWords(string s) {
        string ans = "", tmp;
        istringstream iss(s);
        while(iss >> tmp){
            ans = (tmp + " ") + ans;
        }
        return ans.substr(0, ans.size()-1);
    }
};

方法1
动态规划。从vector的尾元素开始采用自顶向下的动态规划算法。思路：某一运算符号进行运算需要其前面的计算结果
c++
(from yak32)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string s = tokens.back();
        tokens.pop_back();
        if(s == "+" || s == "-" || s == "*" || s == "/"){
            int r2 = evalRPN(tokens);
            int r1 = evalRPN(tokens);
            
            if(s == "+") return r1+r2;
            else if(s == "-") return r1-r2;
            else if(s == "*") return r1*r2;
            else return r1/r2;
        }
        else
            return atoi(s.c_str());
    }
};
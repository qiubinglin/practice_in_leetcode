
方法1
c++
(from StefanPochmann)
class Solution {
public:
    int calculate(string s) {
        istringstream iss("+"+s+"+");
        long long total = 0, term = 0, n;
        char op;
        while(iss >> op){
            if(op == '+' or op == '-'){
                total += term;
                iss >> term;
                term *= 44-op;  //'+'和'-'对应的ASII码值分别为43和45
            }
            else{
                iss >> n;
                if(op == '*'){
                    term *= n;
                }
                else{
                    term /= n;
                }
            }
        }
        return total;
    }
};
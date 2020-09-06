
方法1：

c++
(from zjh08177)
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for(int i = 1; i <= num.size()/2; ++i){
            for(int j = 1; j <= (num.size()-i)/2; ++j){
                if(check(num.substr(0, i), num.substr(i, j), num.substr(i+j))){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool check(string num1, string num2, string remained){
        if((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) return false;
        
        string sum = add(num1, num2);
        
        if(sum == remained) return true;
        if(sum.size() >= remained.size() || remained.compare(0, sum.size(), sum) != 0) return false;
        return check(num2, sum, remained.substr(sum.size()));
    }
    
    string add(string num1, string num2){
        string sum;
        int carry = 0, loopTime = max(num1.size(), num2.size());
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i = 0; i < loopTime; ++i){
            int x = num1.size() > i ? num1[i]-'0' : 0;
            int y = num2.size() > i ? num2[i]-'0' : 0;
            int tmp_sum = x+y+carry;
            carry = tmp_sum/10;
            sum.push_back(tmp_sum%10+'0');
        }
        if(carry) sum.push_back(carry+'0');
        reverse(sum.begin(), sum.end());
        
        return sum;
    }
};


方法1：

c++
class Solution {
public:
    string getHint(string secret, string guess) {
        int m[10] = {0};
        int numA = 0, numB = 0;
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i]) ++numA;
            else{
                ++m[secret[i]-'0'];
                --m[guess[i]-'0'];
            }
        }
        
        int tmp = 0;
        for(int i = 0; i < 10; ++i){
            if(m[i] > 0) tmp += m[i];
        }
        numB = secret.size()-tmp-numA;
        
        return to_string(numA)+"A"+to_string(numB)+"B";
    }
};
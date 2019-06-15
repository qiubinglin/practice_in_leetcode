
方法1：
递归

c++
class Solution {
public:
    string numSet = "-0123456789";
    
    NestedInteger deserialize(string s) {
        int i = 0;
        return recu_deserialize(s, i);
        
    }
    
    NestedInteger recu_deserialize(string &s, int &i){
        NestedInteger res;
        while(i < s.size()){
            if(isNumber(s[i])){
                int last = s.find_first_not_of(numSet, i);
                int val = stoi(s.substr(i, last-i));
                res.add(NestedInteger(val));
                i = last;
            }
            else{
                if(s[i] == '['){
                    NestedInteger ni = recu_deserialize(s, ++i);
                    res.add(ni);
                }
                else if(s[i] == ']'){
                    ++i;
                    return res;
                }
                else ++i;
            }
        }
        NestedInteger result = res.getList().front();
        return result;
    }
    
    bool isNumber(char &c){
        return c == '-' || isdigit(c);
    }
};


方法2：
栈


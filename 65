class Solution {
public:
    int make(char c)
    {
        switch(c)
        {
            case ' ':
                return 0;
            case '-':
            case '+':
                return 1;
            case '.':
                return 3;
            case 'e':
                return 4;
            default:
                if(c >= 48 && c <= 57)
                {
                    return 2;
                }
        }
        return -1;
    }
    bool isNumber(string s) {
        if(s.size() == 0) return false;
        int state = 0;
        vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1});
        vector<vector<int>> transfer({
                {0,  1,  6,  2,  -1},
                {-1, -1, 6,  2,  -1},
                {-1, -1, 3,  -1, -1},
                {8,  -1, 3,  -1, 4},
                {-1, 7,  5,  -1, -1},
                {8,  -1, 5,  -1, -1},
                {8,  -1, 6,  3,  4},
                {-1, -1, 5,  -1, -1},
                {8,  -1, -1, -1, -1},
                });
        for(auto &c : s)
        {
            int id = make(c);
            if(id < 0) return false;
            state = transfer[state][id];
            if(state < 0) return false;
        }
        return finals[state];
    }
};
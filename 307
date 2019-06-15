
方法1：
使用树状数组

c++
class NumArray {
public:
    NumArray(vector<int>& nums) : org(nums){
        BIT.push_back(0);
        for(auto &num : nums){
            BIT.push_back(num);
        }
        
        for(int i = 1; i < BIT.size(); ++i){
            int j = i+(i&(-i));
            if(j < BIT.size()){
                BIT[j] = BIT[j]+BIT[i];
            }
        }
    }
    
    void update(int i, int val) {
        if(val != org[i]){
            add(i, val-org[i]);
            org[i] = val;
        }
    }
    
    int sumRange(int i, int j) {
        return prefixSum(j) - prefixSum(i-1);
    }
    
private:
    void add(int i, int val){
        int idx = i+1;
        while(idx < BIT.size()){
            BIT[idx] += val;
            idx += idx&(-idx);
        }
    }
    
    int prefixSum(int i){
        int idx = i+1, sum = 0;
        while(idx >= 1){
            sum += BIT[idx];
            idx = idx&(idx-1);
        }
        return sum;
    }
    
    vector<int> BIT, org;
};
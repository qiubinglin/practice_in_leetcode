
方法1：

c++
(from r_w)
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hash_dict.find(val) != hash_dict.end()) return false;
        nums.emplace_back(val);  //将新元素置于末尾
        hash_dict[val] = nums.size()-1;  //哈希表中记录该元素对应的索引位置
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // 删除某元素时，交换该元素与尾元素的在nums中的位置并同步哈希表中的信息。
        if(hash_dict.find(val) == hash_dict.end()) return false;
        int last = nums.back();
        nums[hash_dict[val]] = last;
        hash_dict[last] = hash_dict[val];
        nums.pop_back();   //通过每次都是删除尾元素来保证Ο(1)时间复杂度
        hash_dict.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> hash_dict;
};
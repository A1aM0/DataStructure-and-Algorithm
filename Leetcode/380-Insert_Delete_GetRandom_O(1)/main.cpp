/**
 * @brief 常数时间插入、删除和获取随机元素
 * 
 * 设计一个支持在平均 时间复杂度 O(1) 下，执行以下操作的数据结构。
 * insert(val)：当元素 val 不存在时，向集合中插入该项。
 * remove(val)：元素 val 存在时，从集合中移除该项。
 * getRandom：随机返回现有集合中的一项。每个元素应该有相同的概率被返回。
 */

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        // 复杂度限制，所以使用哈希表。
        // 拍脑门想到的是，创建一个vector和一个map，vector存插入的元素，map.key是元素值，map.val存元素在vector中的位置。
        // 为什么要多一个vector，因为getRandom函数，需要相同概率，直接random数组角标，是最靠谱的。
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val) > 0) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.count(val) == 0) return false;
        m[nums.back()] = m[val];
        swap(nums.back(), nums[m[val]]);
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = nums.empty() ? 0 : rand() % nums.size();
        return nums[pos];
    }

private:
    unordered_map<int, int> m;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
 * @brief  前 K 个高频元素
 * 
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { // 要求时间小于对数级
        // O(n)
        unordered_map<int, int> m;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> q; // 升序的优先级队列，当有新插入的数，就pop队头的最小的数
        for (int num : nums) m[num]++; // 哈希，计算重复次数
        for (auto it = m.begin(); it != m.end(); ++it) { // 插入队列
            q.push(pair<int, int>(it->second, it->first));
            if (q.size() > k) q.pop();
        }
        while (k--) { // pop到res里
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};

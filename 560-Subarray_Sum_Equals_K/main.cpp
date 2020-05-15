/*!
 * @brief 和为K的子数组
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 *
 * 说明 :
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        m[0] = 1; // 这步是为什么？
        int pre = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre = pre + nums[i];
            if (m.find(pre - k) != m.end()) res = res + m[pre - k];
            m[pre]++;
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

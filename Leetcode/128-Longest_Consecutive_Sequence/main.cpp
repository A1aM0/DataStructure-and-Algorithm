/*!
 * @brief 最长连续序列
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 * 要求算法的时间复杂度为 O(n)。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map; // first存数组的值，second存该值对应的连续长度
        int max(0);
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i]) > 0) continue; // 遇到重复的数字跳过
            int left = map.count(nums[i] - 1) ? map[nums[i] - 1] : 0; // 找当前值的左侧相邻的数字在不在哈希中，记录它左侧的连续长度
            int right = map.count(nums[i] + 1) ? map[nums[i] + 1] : 0; // 找当前值的右侧相邻的数字在不在哈希中
            int len = left + right + 1; // 当前数字对应的连续长度
            max =  len > max ? len : max; // 更新max
            map[nums[i]] = len; // 在哈希里更新当前数字的连续长度
            map[nums[i] - left] = len; // nums[i]-left指当前数字所在的连续序列里，最左边（最小）的数字是谁，即该连续序列的左边界。相应的，需要更新左边界对应序列的连续长度。
            map[nums[i] + right] = len;
        }
        return max;
    }
};

int main() {
    vector<int> nums{100, 4, 200, 1, 3, 2};
    Solution s;
    std::cout << s.longestConsecutive(nums) << std::endl;
    return 0;
}

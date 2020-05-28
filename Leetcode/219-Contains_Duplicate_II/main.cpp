/*!
 * @brief 存在重复元素 II
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的 绝对值 至多为 k。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (!m[nums[i]].empty()) {
                for (auto pos : m[nums[i]]) {
                    if (i - pos <= k) return true;
                }
            }
            m[nums[i]].push_back(i);
        }
        return false;

//        简化,不必将每个位置都记录，搜索的时候时间复杂度直接就上去了，不满足<=k的时候，可以直接更新新的位置，若后面还有相同的数字，之前记录的必不满足，所以不用考虑
//        unordered_map<int, int> m;
//        for (int i = 0; i < nums.size(); ++i) {
//            if (m.count(nums[i]) > 0) {
//                if (i - m[nums[i]] <= k) return true;
//            }
//            m[nums[i]] = i;
//        }
//        return false;
    }
};

int main() {
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3;
    vector<int> nums2 = {1,0,1,1};
    int k2 = 1;
    vector<int> nums3 = {1,5,9,1,5,9};
    int k3 = 2;

    Solution s;

    std::cout << "result is " << (s.containsNearbyDuplicate(nums3, k1) ? "true" : "false") << std::endl;
    return 0;
}

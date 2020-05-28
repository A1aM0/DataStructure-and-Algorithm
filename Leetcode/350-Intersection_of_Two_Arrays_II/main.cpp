/*!
 * @brief 两个数组的交集 II
 *
 * 给定两个数组，编写一个函数来计算它们的交集。
 *
 * 示例 1:
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 *
 * 示例 2:
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 *
 * 说明:
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 *
 * 进阶:
 * 如果给定的数组已经排好序呢？你将如何优化你的算法？
 * 如果 nums1 的大小比 nums2 小很多，哪种方法更优？
 * 如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1); //如果nums1的长度小，则继续；反之，把nums2放到前面当作nums1
        unordered_map<int, int> mp; // 记录短的数组的数字
        vector<int> res;
        for (int i = 0; i < nums1.size(); ++i) { // 自增的是当前数字出现的次数
            mp[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (mp[nums2[i]] > 0) {
                mp[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    Solution s;
    vector<int> res = s.intersect(nums1, nums2);
    for (auto num : res) std::cout << num << endl;
    return 0;
}

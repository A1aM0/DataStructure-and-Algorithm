/*!
 * @brief 搜索插入位置
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 你可以假设数组中无重复元素。
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0; ///< 位置
        auto it = nums.begin();
        while (target > *it) {
            ++pos;
            ++it;
            if (pos == nums.size()) {
                nums.emplace_back(target);
                break;
            }
        }
        if (target == nums[pos]) return pos;
        else nums.insert(it,target);

        return pos;
    }

    /*!
     * @details !!!我靠原题居然是只要返回所在位置，或者返回将要插入的位置，不用真的插入。。。完全没必要insert()
     * @param nums 目标向量
     * @param target 目标值
     * @return 位置
     *
     * @warning 发现了个问题，几乎按照统计里最快的解法做的，但是用时16ms，远超上个方法的4ms，不懂？？？内存占用是少了0.1M
     */
    int searchInsert2(vector<int>& nums, int target) {
        int pos = 0;
        for (pos; pos < nums.size(); pos++) {
            if (nums[pos] < target) continue;
            else return pos;
        }
        return pos;
    }
};

int main() {
    vector<int> num = {1, 3, 5, 6};
    int target1 = 5, target2 =2, target3 = 7,target4 = 0;
    Solution solution;
    cout << solution.searchInsert(num, target2);

    return 0;
}
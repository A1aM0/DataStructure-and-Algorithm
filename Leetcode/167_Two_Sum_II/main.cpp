/*!
 * @brief 两数之和 II - 输入有序数组
 * @details
 * 给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
 * 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
 *
 * @warning
 * 返回的下标值（index1 和 index2）不是从零开始的；
 * 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size() - i - 1; i < j; ) {
            if (numbers[i] + numbers[j] == target) return {i + 1, j + 1};
            else if (numbers[i] + numbers[j] < target) ++i;
            else --j;
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums2 = {5, 25, 75};
    int target2 = 100;

    Solution s;
    vector<int> res = s.twoSum(nums2, target2);
    cout << res[0] << " and " << res[1];
    return 0;
}
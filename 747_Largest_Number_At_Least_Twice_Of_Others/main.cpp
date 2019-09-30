/*!
 * @brief 至少是其他数字两倍的最大数
 * 在一个给定的数组nums中，总是存在一个最大元素 。
 * 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
 * 如果是，则返回最大元素的索引，否则返回-1。
 *
 * @warning nums 的长度范围在[1, 50]，每个 nums[i] 的整数范围在 [0, 100].
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*!
     * 找到第一大和第二大的数比较，坑是数组是乱序
     * @param nums
     * @return
     */
    int dominantIndex(vector<int>& nums) {
        int first = 0, second = 0, index1 = -1, index2;
        if(nums.empty()) return -1;
        for(int i = 0; i < nums.size(); i++) {
            if(first < nums[i]) {
                second = first;
                index2 = index1;
                first = nums[i];
                index1 = i;
                continue;
            }
            if (second < nums[i]) {
                second = nums[i];
                index2 = i;
            }
        }
        if(first >= (second * 2)) return index1;
        return -1;
    }
};

int main() {
    vector<int> nums1 = {3, 6, 1, 0};
    vector<int> nums2 = {1, 2, 3, 4};
    vector<int> nums3 = {0, 0, 3, 2};

    Solution s;
    cout << "result:" << s.dominantIndex(nums2);
    return 0;
}
/*!
 * @brief 寻找数组的中心索引
 *
 * @details
 * 给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
 * 我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
 * 如果数组不存在中心索引，那么我们应该返回 -1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。
 *
 * @warning nums 的长度范围为 [0, 10000]。任何一个 nums[i] 将会是一个范围在 [-1000, 1000]的整数。
 */
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*!
     * 硬解，时间复杂度n^2，巨慢
     * @param nums
     * @return
     */
    int pivotIndex(vector<int>& nums) {
        if (nums.empty()) return -1;
        for (int i = 0; i < nums.size(); i++){
            vector<int> result = addLeftAndRight(nums, i);
            if (result[0] == result[1]) return i;
        }
        return -1;
    }

    /*!
     * 硬解的加法计算，计算某位置的左右之和
     * @param nums
     * @param index
     * @return
     */
    vector<int> addLeftAndRight(vector<int>& nums, int index){
        int left = 0, right = 0;
        for (int i = 0; i <= index; i++){
            if (index == 0) break;
            left = left + nums[i];
        }

        for (int i = index + 1; i < nums.size(); i++) {
            if (index == nums.size()) break;
            right = right + nums[i];
        }

        return {left, right};
    }
};

int main() {
    vector<int> nums1 = {1, 7, 3, 6, 5, 6};
    vector<int> nums2 = {1, 2, 3};
    vector<int> nums3 = {-1,-1,-1,0,1,1};
    Solution s;
    cout << "result: " << s.pivotIndex(nums3);
    return 0;
}
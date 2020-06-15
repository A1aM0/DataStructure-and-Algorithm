/*!
 * @brief 递增的三元子序列
 *
 * 给定一个未排序的数组，判断这个数组中是否存在长度为 3 的递增子序列。
 *
 * 数学表达式如下:
 * 如果存在这样的 i, j, k,  且满足 0 ≤ i < j < k ≤ n-1，
 * 使得 arr[i] < arr[j] < arr[k] ，返回 true ; 否则返回 false 。
 * 说明: 要求算法的时间复杂度为 O(n)，空间复杂度为 O(1) 。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int small = INT_MAX, mid = INT_MAX;
        for (int num : nums) {
            if (num < small) {
                small = num; // 题目要求下标也要递增，所以不能更新mid=small，这样会破坏下标的递增性，可参考测试nums3
            } else if (num > small && num < mid) {
                mid = num;
            } else if (num > mid) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums1{1,2,3,4,5};
    vector<int> nums2{5,4,3,2,1};
    vector<int> nums3{2,4,-2,-3};
    Solution s;
    std::cout << s.increasingTriplet(nums1) << std::endl;
    std::cout << s.increasingTriplet(nums2) << std::endl;
    std::cout << s.increasingTriplet(nums3) << std::endl;
    return 0;
}

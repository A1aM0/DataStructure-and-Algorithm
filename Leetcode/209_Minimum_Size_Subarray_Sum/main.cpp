/*!
 * @brief 长度最小的子数组
 * @details
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。
 * 如果不存在符合条件的连续子数组，返回 0。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*!
     * 双指针，时间复杂度O(n)
     * 设一个窗口，使窗口内的数加起来满足条件，保持长度右移一个单位，检查里面的数是否满足条件，再删去窗口的第一个数，继续检查；
     * 直到找出当前窗口的最小长度，再和总的最小长度比；
     * 比完了继续右移，直到结束。
     */
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = INT_MAX, sum = 0, begin = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while (sum >= s) {
                len = len < i - begin + 1 ? len : i - begin + 1;
                sum -= nums[begin];
                ++begin;
            }
        }
        return (len != INT_MAX) ? len : 0;
    }
    /*!
     * 二分法，时间复杂度O(n logn)
     */
    int minSubArrayLen2(int s, vector<int>& nums) {
        return 0;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int s = 7;

    Solution solution;
    cout << "result is: " << solution.minSubArrayLen(s, nums);
    return 0;
}
/*!
 * @brief 分割数组的最大值
 *
 * 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。设计一个算法使得这 m 个子数组各自和的最大值最小。
 *
 * 注意:
 * 数组长度 n 满足以下条件:
 * 1 ≤ n ≤ 1000
 * 1 ≤ m ≤ min(50, n)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // 二分。
        // 范围左边界，大于等于整个数组的最大值，
        // 范围右边界小于等于整个数组的和。
        long int left = INT_MIN;
        long int right = 0;
        for (int x : nums) {
            right += x;
            left = left > x ? left : x;
        }

        // 假设中点mid就是 “每一个数组和的最大值”们 的最小值
        // 那么每一个数组和必定<=mid
        // 用这个值来对数组进行从头分割，一旦当前数组和>mid,就结束该数组，开启一个新数组
        // 如果用这个mid创建的数组数量，比m还多，说明这个值定小了，所以二分查找取右半！
        // 如果用这个mid创建的数组数量，比m少了，说明这个值定大了，所以二分查找取左半！
        while (left < right) {
            int m_compare = 1; // 末尾还有一个子数组我们没有统计，这里把它加上，或者在后面自增1
            long sum = 0;
            long mid = left + (right - left) / 2;
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i]; // 根据题意，mid本为各个子数组的最大值，则在加上这个数之前，这一轮所在的子数组的和最大也就等于mid，这也是后面更新sum的值为当前nums[i]的原因
                if (sum > mid) {
                    m_compare++;
                    sum = nums[i]; // 当前数组已经超过mid，要停止这个数组，这个数变为下一个数组的开头
                }
            }
            if (m_compare > m) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int dp_splitArray(vector<int> &nums, int m) {
        vector<vector<long>> dp(nums.size() + 1, vector<long>(m + 1, LONG_MAX));
        dp[0][0] = 0;
        vector<long> prefixSum(nums.size() + 1, 0); // 记录前缀和
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], prefixSum[i] - prefixSum[k]));
                }
            }
        }
        return dp.back().back();
    }
};

int main() {
    vector<int> nums{7,2,5,10,8};
    Solution s;
    std::cout << s.splitArray(nums, 2) << std::endl;
    std::cout << s.dp_splitArray(nums, 2) << std::endl;
    return 0;
}

/*!
 * @brief 分割等和子集
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 *
 * 注意:
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 对于和为sum的集合，是否能划分为两个相等子集，等价于能否利用集合内的元素 凑成 sum/2，
    // 也就是n个物品 背包容量为sum/2 每个物品只能取一次的01背包
    // 状态表示: f[i][j] 表示用前i种物品能否恰好填满容积为j的背包
    // 状态转移: f[i][j] = f[i-1][j]||f[i-1][j-nums[i-1]] 即不取第i件或取第i件
    // 滚动数组优化 f[j] = f[j]||f[j-nums[i-1]]
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) return false;

        int valSum = sum / 2;
        int n = nums.size();
        vector<bool> dp(valSum + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = dp.size() - 1; j >= nums[i - 1]; j--) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }
        return dp.back();
    }
};

int main() {
    vector<int> nums1{1, 5, 11, 5};
    vector<int> nums2{1, 2, 3, 5};
    Solution s;
    std::cout << (s.canPartition(nums1) ? "true" : "false") << std::endl; // T
    std::cout << (s.canPartition(nums2) ? "true" : "false") << std::endl; // F
    return 0;
}

/*!
 * @brief 打家劫舍
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) { // dp[i]可以表示为 max(dp[i-2] + i, dp[i-1])
        int dp1 = 0, dp2 = 0; // 让 d[-1] = 0, d[0] = 0
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = std::max(dp1 + nums[i], dp2);
            dp1 = dp2;
            dp2 = tmp;
        }
        return dp2;
    }
};

int main() {
//    std::vector<int> nums{1,2,3,1};
    std::vector<int> nums{2,7,9,3,1};
    Solution s;
    std::cout << s.rob(nums) << std::endl;
    return 0;
}

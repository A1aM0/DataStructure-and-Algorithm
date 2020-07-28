/*!
 * @brief 最长上升子序列
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // dp,O(n^2)
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = 0;
        for (int len : dp) {
            res = max(res, len);
        }

        return res;
    }
};

int main() {
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution s;
    std::cout << s.lengthOfLIS(nums) << std::endl;
    return 0;
}

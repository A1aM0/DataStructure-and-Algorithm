/*!
 * @brief 最小路径和
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (i == 0) {
                    dp[i + 1][j + 1] = dp[i + 1][j];
                }
                else if (j == 0) {
                    dp[i + 1][j + 1] = dp[i][j + 1];
                }
                else {
                    dp[i + 1][j + 1] = dp[i][j + 1] > dp[i + 1][j] ? dp[i + 1][j] : dp[i][j + 1];
                }
                dp[i + 1][j + 1] += grid[i][j];
            }
        }
        return dp.back().back();
    }
};

int main() {
    vector<vector<int>> nums = {{1,3,1}, {1,5,1}, {4,2,1}};
    Solution s;
    std::cout << s.minPathSum(nums) << std::endl;
    return 0;
}

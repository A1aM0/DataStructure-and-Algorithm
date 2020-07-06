/*!
 * @brief 不同路径 II
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 *
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 说明：m 和 n 的值均不超过 100。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) { // 思路比较好想：到达某一个位置的可能性只能是它左边格子的可能性加上边格子的可能性，转移方程就出来了，需要注意边界条件
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int col = obstacleGrid[0].size(), row = obstacleGrid.size();
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
                else if (obstacleGrid[i][j] == 0) {
                    if (i == 0 && j == 0) dp[i][j] = 1;
                    else if (i == 0) dp[i][j] = dp[i][j - 1];
                    else if (j == 0) dp[i][j] = dp[i - 1][j];
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[row - 1][col - 1];
    }
};

int main() {
    vector<vector<int>> grid{{0,0,0}, {0,1,0}, {0,0,0}};
    Solution s;
    std::cout << s.uniquePathsWithObstacles(grid) << std::endl;
    return 0;
}

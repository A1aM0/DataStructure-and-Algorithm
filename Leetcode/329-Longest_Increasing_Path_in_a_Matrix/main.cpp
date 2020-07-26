/*!
 * @brief 矩阵中的最长递增路径
 *
 * 给定一个整数矩阵，找出最长递增路径的长度。
 * 对于每个单元格，你可以往上，下，左，右四个方向移动。 你不能在对角线方向上移动或移动到边界外（即不允许环绕）。
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty() == 0) return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0)); // 用dp数组记忆原矩阵上某个点对应的最长递增路径的长度，要是不为0，就不用重复查找了
        int res = 0;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max(res, dfs(matrix, i, j, dp));
            }
        }
        return res;
    }
    int  dfs (vector<vector<int>> &matrix, int entry_x, int entry_y, vector<vector<int>> &dp) {
        if (dp[entry_x][entry_y] != 0) return dp[entry_x][entry_y];
        dp[entry_x][entry_y]++;
        int up = 0, down = 0, left = 0, right = 0;
        if (entry_y > 0 && matrix[entry_x][entry_y - 1] > matrix[entry_x][entry_y]) left = dfs(matrix, entry_x, entry_y - 1, dp);
        if (entry_y < matrix[0].size() - 1 && matrix[entry_x][entry_y + 1] > matrix[entry_x][entry_y]) right = dfs(matrix, entry_x, entry_y + 1, dp);
        if (entry_x > 0 && matrix[entry_x - 1][entry_y] > matrix[entry_x][entry_y]) up = dfs(matrix, entry_x - 1, entry_y, dp);
        if (entry_x < matrix.size() - 1 && matrix[entry_x + 1][entry_y] > matrix[entry_x][entry_y]) down = dfs(matrix, entry_x + 1, entry_y, dp);
        dp[entry_x][entry_y] = max(max(max(left, right), up), down) + 1;
        return dp[entry_x][entry_y];
    }
};
int main() {
    vector<vector<int>> matrix{{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    Solution s;
    std::cout << s.longestIncreasingPath(matrix) << std::endl;
    return 0;
}

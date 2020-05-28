/*!
 * @brief 最大正方形
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // 暴力的话时间复杂度太高O(mn) * O(min(n^2, m^2))
        // dp，空间换时间,都是O(mn)
        if (matrix.empty() || matrix[0].empty()) return 0; //空矩阵

        int rows = matrix.size();
        int columns = matrix[0].size();
        int longestSide = 0;
        vector<vector<int>> dp(rows, vector<int>(columns, 0));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                // 从矩阵左上角进入，dp(i,j)表示该点作为一个正方形的右下角的话正方形的边长。
                // 那么每一个dp(i,j)都可以由他左边和上边的邻点得到：dp(i,j) = min(dp(i-1,j), dp(i,j-1), dp(i-1,j-1)) + 1。
                // 得到上式的前提是，该点(i,j)处的值为1。
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i][j] = 1; //边界，当计算到的点落到了边界上，那么最大正方形就是他自己，边长为1。
                    else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                longestSide = dp[i][j] > longestSide ? dp[i][j] : longestSide;
            }
        }
        return longestSide * longestSide;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    Solution s;
    std::cout << "result is " << s.maximalSquare(matrix) << std::endl;
    return 0;
}

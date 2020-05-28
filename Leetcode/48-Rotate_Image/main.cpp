/*!
 * @brief 旋转图像
 *
 * 给定一个 n × n 的二维矩阵表示一个图像。
 * 将图像顺时针旋转 90 度。
 *
 * 说明：
 * 你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 主要是要发现角标的规律，顺时针旋转90° = 先沿竖直方向中心线翻转 + 再沿主对角线翻转
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // 方阵阶数
        int mid = n / 2;
        // 竖直对称
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < mid; ++j) {
                int tmp;
                tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = tmp;
            }
        }
        // 对角线对称
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]); // 注意角标的变换
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);
    for (auto row : matrix) {
        for (auto col : row) cout << col << " ";
        cout << endl;
    }
    return 0;
}

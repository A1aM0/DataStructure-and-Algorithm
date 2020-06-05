/*!
 * @brief 矩阵置零
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 *
 * 进阶:
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) { // O(m+n)的空间
        vector<pair<int, int>> pos;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) pos.push_back({i, j});
            }
        }
        for (pair<int, int> p : pos) {
            for (int i = 0; i < matrix.size(); ++i) matrix[i][p.second] = 0;
            for (int i = 0; i < matrix[0].size(); ++i) matrix[p.first][i] = 0;
        }
    }

    // 首先要记录下第一行和第一列是否全部为零（就是第一行第一列内是否有零，最后再进行处理）
    // 遍历除第一行第一列以外的数据，如果有修改第一行第一列对应位置为零
    // 根据第一行第一列修改matrix
    // 修改第一行第一列
    void setZeroes2(vector<vector<int>>& matrix) { // 直接搬运的，空间O(1)
        if (matrix.size() == 0) return;
        const int m = matrix.size();
        const int n = matrix[0].size();
        bool firstRow = false;
        bool firstCol = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                const int item = matrix[i][j];
                if (item == 0) {
                    if (i == 0) {
                        firstRow = true;
                    }
                    if (j == 0) {
                        firstCol = true;
                    }
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                const int item = matrix[i][j];
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // 修改第一行和第一列
        if (firstRow) {
            for (int i = 0; i < n; i++) {
                matrix[0][i] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{{1,1,1}, {1,0,1}, {1,1,1}};
//    vector<vector<int>> matrix{{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
    Solution s;
    s.setZeroes(matrix);
    for (auto row : matrix) {
        for(auto num : row) cout << num << " ";
        cout << endl;
    }
    return 0;
}

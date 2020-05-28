/*!
 * @brief 对角线遍历
 *
 * 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素
 *
 * @warning 给定矩阵中的元素总数不会超过 100000
 */

#include <iostream>
#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};

        int row = matrix.size(); ///<行数
        int column = matrix[0].size(); ///<列数
        int x = 0, y = 0;
        vector<int> result;

        for (int i = 0; i < row + column; ++i){ ///< i表示result的第i个元素
            if (i % 2 == 0) { ///< 第i条对角线，偶数时方向朝右上，奇数时方向朝右下
                x = i < row ? i : row - 1; ///< 对角线大于行数的话，就从最后一行算其实行数
                y = i - x;
                while (x >= 0 && y < column) {
                    result.push_back(matrix[x][y]);
                    --x;
                    ++y;
                }
            }
            else if (i % 2 == 1) {
                y = i < column ? i : column - 1;
                x = i - y;
                while (x < row && y >= 0) {
                    result.push_back(matrix[x][y]);
                    ++x;
                    --y;
                }
            }
        }
        return result;
    }
};

/*!
 * 输出测试结果
 * @param matrix
 */
void printout(vector<int>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        cout << matrix[i] << " ";
    }
}
int main() {
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};

    Solution s;
    vector<int> result = s.findDiagonalOrder(matrix1);
    cout << "result: ";
    printout(result);
    return 0;
}
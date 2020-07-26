/*!
 * @brief 搜索二维矩阵 II
 *
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：
 *
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int i = matrix.size() - 1, j = 0;
        while (i >= 0 && j < matrix[0].size()) {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) {
                j++;
            }
            else if (matrix[i][j] > target) {
                i--;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> matrix{{1,   4,  7, 11, 15},
                               {2,   5,  8, 12, 19},
                               {3,   6,  9, 16, 22},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};
    vector<vector<int>> matrix2{{5}, {6}};
    Solution s;
    std::cout << s.searchMatrix(matrix, 5) << std::endl;
    std::cout << s.searchMatrix(matrix, 20) << std::endl;
    std::cout << s.searchMatrix(matrix2, 6) << std::endl;
    return 0;
}

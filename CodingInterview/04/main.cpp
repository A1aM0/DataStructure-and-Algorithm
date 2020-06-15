/*!
 * @brief  二维数组中的查找
 *
 * 在一个 n * m 的二维数组中，
 * 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 *
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 从二维数组的右上角开始查找。
    // 如果当前元素大于目标值，说明当前元素的下边的所有元素都一定大于目标值，
    // 因此往下查找不可能找到目标值，往左查找可能找到目标值。
    // 如果当前元素小于目标值，说明当前元素的左边的所有元素都一定小于目标值，
    // 因此往左查找不可能找到目标值，往下查找可能找到目标值。
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row = matrix.size(), col = matrix[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (target == matrix[i][j]) return true;
            else if (target > matrix[i][j]) i++;
            else j--;
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
    Solution s;
    std::cout << s.findNumberIn2DArray(matrix, 5) << std::endl;
    std::cout << s.findNumberIn2DArray(matrix, 20) << std::endl;
    return 0;
}

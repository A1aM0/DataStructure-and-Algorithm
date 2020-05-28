/*!
 * @brief 螺旋矩阵
 * @details 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        int row = matrix.size(); //< 行数
        int column = matrix[0].size(); //< 列数
        int i = 0;
        int up = 0, down = row - up - 1, left = 0, right = column - left - 1; //< 边界
        vector<int> result(row * column); ///< 可以不用初始化数组大小，用push_back()方法把值推进去就行，这样也不用初始化i了，直接while(true)
        /// 每次while循环都是转一圈
        while (i < row * column){
            /// 向右
            for(int y = left; y <= right; ++y) {
                result[i] = matrix[up][y];
                ++i;
            }
            if(++up > down) break;
            /// 向下
            for(int x = up; x <= down; ++x) {
                result[i] = matrix[x][right];
                ++i;
            }
            if(--right < left) break;
            /// 向左
            for(int y = right; y >= left; --y) {
                result[i] = matrix[down][y];
                ++i;
            }
            if(--down < up) break;
            /// 向上
            for(int x = down; x >= up; --x) {
                result[i] = matrix[x][left];
                ++i;
            }
            if(++left > right) break;
        }
        return result;
    }
};

int main() {
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    Solution s;
    vector<int> result = s.spiralOrder(matrix2);
    for (int i = 0; i < result.size(); ++i) {
        printf("%d ",result[i]);
    }
    return 0;
}
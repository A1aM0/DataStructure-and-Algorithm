/*!
 * @brief 杨辉三角 II
 * @details 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 第一版，只为达成空间复杂度为O(k)，k为要输出的行号
    // 基本思路当前行的第i个元素为上一行第i个元素加第i-1个，只用一行，配合临时变量保存之前的i-1号元素，加当前数值
    vector<int> getRow(int rowIndex) {
        ++rowIndex;
        if (rowIndex == 0) return {};
        if (rowIndex == 1) return {1};
        if (rowIndex == 2) return {1, 1};
        vector<int> triangle = {1, 1};
        for (int row = 3; row <= rowIndex; ++row) { // row是行号
            int current, front = 1;
            for (int i = 0; i < row-1; ++i) {
                if (i == 0) triangle[i] = 1;
                current = triangle[i];
                if (i > 0) {
                    triangle[i] += front;
                    front = current;
                }
            }
            triangle.push_back(1);
        }
        return triangle;
    }
};

int main() {
    int rowIndex = 3; // output: [1, 3, 3, 1]
    Solution s;
    vector<int> res = s.getRow(rowIndex);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
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

    // 把上面的简化一下，主体思路不变
    vector<int> getRow2(int rowIndex) { // 认为0代表第一行，则rowIndex代表rowIndex+1行
        int front = 1;
        vector<int> triangle;
        triangle.push_back(1); // 第一个元素直接填1
        for (int row = 1; row <= rowIndex; ++row) { // 直接从第二行开始，若输入行号为0（第一行）的话，出循环直接返回
            for (int i = 1; i < row; ++i) {
                int tmp = triangle[i];
                triangle[i] = triangle[i] + front;
                front = tmp;
            }
            triangle.push_back(1); // 最后给补上最后一位1
        }
        return triangle;
    }

    // 优化2：从后往前填入数字，省去了提供临时变量的额外内存
    vector<int> getRow3(int rowIndex) {
        int front = 1;
        vector<int> triangle;
        triangle.push_back(1);
        for (int row = 1; row <= rowIndex; ++row) { // 前四步与之前一样
            for (int i = row - 1; i > 0; --i) { // 从倒数第二位元素开始，到第二位元素结束
                triangle[i] = triangle[i] + triangle[i - 1];
            }
            triangle.push_back(1);
        }
        return triangle;
    }
};

int main() {
    int rowIndex = 3; // output: [1, 3, 3, 1]
    Solution s;
    vector<int> res = s.getRow3(rowIndex);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}
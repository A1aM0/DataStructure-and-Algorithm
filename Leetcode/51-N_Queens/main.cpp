/*!
 * @brief N皇后
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，
 * 该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        backTrace(res, tmp, n, 0);
        return res;
    }
    void backTrace(vector<vector<string>> &res, vector<string> &tmp, int n, int row) {
        if (n == row) {
            res.emplace_back(tmp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (valid(row, col, tmp, n)) {
                tmp[row][col] = 'Q';
                backTrace(res, tmp, n, row + 1);
                tmp[row][col] = '.';
            }
        }
    }
    bool valid (int row, int col, vector<string> &array, int n) {
        for (int i = 0; i < row; i++) {
            if (array[i][col] == 'Q') return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (array[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (array[i][j] == 'Q') return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<string>> res = s.solveNQueens(4);
    for (vector<string> solov : res) {
        for (string str : solov) {
            cout << str << endl;
        }
        cout << endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

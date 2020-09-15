/*!
 * @brief 解数独
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 一个数独的解法需遵循如下规则：
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 空白格用 '.' 表示。
 *
 * Note:
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

    bool dfs (vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;

                for (char k = '1'; k <= '9'; k++) {
                    if (check(board, i, j, k)) {
                        board[i][j] = k;
                        if (dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool check (vector<vector<char>> &board, int x, int y, char k) {
        for (int i = 0; i < 9; i++) {
            if (board[x][i] == k) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (board[i][y] == k) return false;
        }
        x = x / 3 * 3;
        y = y / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[x + i][y + j] == k) return false;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    s.solveSudoku(board);
    for (auto row : board) {
        for (auto ch : row) cout << ch << " ";
        cout << endl;
    }
    return 0;
}

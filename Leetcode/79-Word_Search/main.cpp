/*!
 * @brief 单词搜索
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 *
 * @note
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++) {
                // 以每一个字母作为起点，检查是否满足
                if(backTrace(board, i, j, 0, word, flag))
                    return true;
            }
        }
        return false;
    }

    bool backTrace (vector<vector<char>> &board, int x, int y, int start, string word, vector<vector<bool>> &flag) {
        // 矩阵搜到的每个字母都和字符串匹配上了
        if (start == word.size()) return true;
        // 矩阵越界、矩阵当前字母与字符串不匹配，false
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] != word[start]) return false;

        if (!flag[x][y]) { // 当前位置的字母匹配上字符串了，且没被访问过，继续搜索其四周的位置是否继续匹配
            flag[x][y] = true;
            if (backTrace(board, x + 1, y, start + 1, word, flag)
            || backTrace(board, x - 1, y, start + 1, word, flag)
            || backTrace(board, x, y + 1, start + 1, word, flag)
            || backTrace(board, x, y - 1, start + 1, word, flag))
                return true;
            flag[x][y] = false;
        }
        return false;
    }
};

int main() {
    vector<vector<char>> matrix{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
    Solution s;
    std::cout << (s.exist(matrix, "ABCCED") ? "true" : "false") << std::endl;
    std::cout << (s.exist(matrix, "SEE") ? "true" : "false") << std::endl;
    std::cout << (s.exist(matrix, "ABCB") ? "true" : "false") << std::endl;
    return 0;
}

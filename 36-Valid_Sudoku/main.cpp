/**
 * @brief  有效的数独
 * 
 * 判断一个 9x9 的数独是否有效。只需要根据以下规则，验证已经填入的数字是否有效即可。
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row[9], column[9], box[9]; // 每行、每列、每个小九格，各建一个哈希，key为数独里的值，value为出现的次数
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) { // 一次遍历二维数组
                if (board[i][j] != '.') {
                    // 遍历到的数字查询所在的行、列、box中查询，先查询后value++，如果查回来是0，则不执行语句；如果查询回来不为0，那么表示已经有了，返回false
                    if (row[i][board[i][j]]++ || column[j][board[i][j]]++ || box[i / 3 * 3 + j / 3][board[i][j]]++) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

/*!
 * @brief 扫雷游戏
 *
 * 让我们一起来玩扫雷游戏！
 * 给定一个代表游戏板的二维字符矩阵。
 * 'M' 代表一个未挖出的地雷，
 * 'E' 代表一个未挖出的空方块，
 * 'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，
 * 数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，
 * 'X' 则表示一个已挖出的地雷。
 *
 * 现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），
 *
 * 根据以下规则，返回相应位置被点击后对应的面板：
 * 如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
 * 如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
 * 如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
 * 如果在此次点击中，若无更多方块可被揭露，则返回面板。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board[click[0]][click[1]] == 'M') board[click[0]][click[1]] = 'X';
        else dfs(board, click[0], click[1]);
        return board;
    }

    void dfs (vector<vector<char>> &board, int x, int y) {
        if (x < 0 || x >= board.size() || y < 0 || y > board[0].size()) return;
        else if (board[x][y] == 'E') {
            char cnt = '0';
            for (int i = 0; i < 8; i++) {
                int xx = x + xOffset[i], yy = y + yOffset[i];
                if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()) {
                    cnt += board[xx][yy] == 'M';
                }
            }
            if (cnt > '0') {
                board[x][y] = cnt;
            }
            else {
                board[x][y] = 'B';
                for (int i = 0; i < 8; i++) {
                    int xx = x + xOffset[i], yy = y + yOffset[i];
                    if (xx >= 0 && xx < board.size() && yy >= 0 && yy < board[0].size()) {
                        dfs(board, xx, yy);
                    }
                }
            }
        }
    }

    int xOffset[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int yOffset[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
};

int main() {
    vector<vector<char>> board = {{'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'M', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'},
                                  {'E', 'E', 'E', 'E', 'E'}};
    vector<int> click{3, 0};
    Solution s;
    s.updateBoard(board, click);
    for (vector<char> vec : board) {
        for (char ch : vec) {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}

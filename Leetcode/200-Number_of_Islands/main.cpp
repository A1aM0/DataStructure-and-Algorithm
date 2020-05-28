/*!
 * @brief 岛屿数量
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int rows = grid.size();
        int columns = grid[0].size();

        int numIsland = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] == '1') {
                    queue<pair<int, int>> coordinate;
                    coordinate.push({i, j});
                    grid[i][j] == '0'; // 标记记录过了
                    numIsland++;
                    while (!coordinate.empty()) { // bfs
                        auto tmpCoords = coordinate.front();
                        coordinate.pop();
                        auto tmpRow = tmpCoords.first, tmpCol = tmpCoords.second;
                        if (tmpRow - 1 >= 0 && grid[tmpRow - 1][tmpCol] == '1') { // 判断顺序，首先不能越界，其次才能判断是否满足条件
                            grid[tmpRow - 1][tmpCol] = '0';
                            coordinate.push({tmpRow - 1, tmpCol});
                        }
                        if (tmpRow + 1 < rows && grid[tmpRow + 1][tmpCol] == '1') {
                            grid[tmpRow + 1][tmpCol] = '0';
                            coordinate.push({tmpRow + 1, tmpCol});
                        }
                        if (tmpCol - 1 >= 0 && grid[tmpRow][tmpCol - 1] == '1') {
                            grid[tmpRow][tmpCol - 1] = '0';
                            coordinate.push({tmpRow, tmpCol - 1});
                        }
                        if (tmpCol + 1 < columns && grid[tmpRow][tmpCol + 1] == '1') {
                            grid[tmpRow][tmpCol + 1] = '0';
                            coordinate.push({tmpRow, tmpCol + 1});
                        }
                    }
                }
            }
        }
        return numIsland;
    }
};

int main() {
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},{'0', '0', '0', '0', '0'}};
    Solution s;
    cout << "result is: " << s.numIslands(grid) << endl;
    return 0;
}

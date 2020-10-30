/*!
 * @brief 463. 岛屿的周长
 *
 * 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
 * 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 *
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // 只有一个岛屿。一块土地原则上会带来4个周长，但岛上的土地存在接壤，每一条接壤，会减掉2个边长。
        // 所以，总周长 = 4 * 土地个数 - 2 * 接壤边的条数。
        // 遍历矩阵，遍历到土地，就 land++，如果它的右/下边也是土地，则 border++，遍历结束后代入公式。
        int land = 0;//土地数量
        int border = 0;//接壤边的条数

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    ++land;
                    if (i < grid.size() - 1 && grid[i + 1][j] == 1) {
                        // 该土地的下方有土地就说明下面这条边就是接壤边
                        ++border;
                    }
                    if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {
                        // 该土地的右方有土地就说明右面这条边就是接壤边
                        ++border;
                    }
                }
            }
        }
        return 4 * land - 2 * border;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    std::cout << s.islandPerimeter(grid) << std::endl;
    return 0;
}

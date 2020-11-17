/*!
 * @brief 距离顺序排列矩阵单元格
 *
 * 给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。
 * 另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。
 * 返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，
 * 其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈顿距离，|r1 - r2| + |c1 - c2|。
 * （你可以按任何满足此条件的顺序返回答案。）
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<bool>> visited(R, vector<bool>(C, false)); ///< 标记入队的位置
        vector<vector<int>> res;
        queue<pair<int, int>> q; ///< BFS的队列
        q.push({r0, c0});
        visited[r0][c0] = true;

        while (!q.empty()) {
            pair<int, int> tmp = q.front();
            q.pop();
            int x = tmp.first, y = tmp.second;
            res.emplace_back(vector<int>{x, y});
            if (x + 1 < R && !visited[x + 1][y]) {
                q.push({x + 1, y});
                visited[x + 1][y] = true;
            }
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                q.push({x - 1, y});
                visited[x - 1][y] = true;
            }
            if (y + 1 < C && !visited[x][y + 1]) {
                q.push({x, y + 1});
                visited[x][y + 1] = true;
            }
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                q.push({x, y - 1});
                visited[x][y - 1] = true;
            }
        }
        return res;
    }
};

int main() {
    auto func = [](int R, int C, int r0, int c0) {
        Solution s;
        vector<vector<int>> res;
        res = s.allCellsDistOrder(R, C, r0, c0);
        for (auto row : res) {
            for (auto n : row) {
                cout << n << " ";
            }
            cout << endl;
        }
    };
//    func(1, 2, 0, 0);
    func(2, 2, 0, 1);
//    func(2, 3, 1, 2);
    return 0;
}

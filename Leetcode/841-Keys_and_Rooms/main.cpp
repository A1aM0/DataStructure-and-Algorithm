/*!
 * @brief 钥匙和房间
 *
 * 有 N 个房间，开始时你位于 0 号房间。每个房间有不同的号码：0，1，2，...，N-1，
 * 并且房间里可能有一些钥匙能使你进入下一个房间。
 * 在形式上，对于每个房间 i 都有一个钥匙列表 rooms[i]，
 * 每个钥匙 rooms[i][j] 由 [0,1，...，N-1] 中的一个整数表示，其中 N = rooms.length。
 * 钥匙 rooms[i][j] = v 可以打开编号为 v 的房间。
 * 最初，除 0 号房间外的其余所有房间都被锁住。
 *
 * 你可以自由地在房间之间来回走动。
 * 如果能进入每个房间返回 true，否则返回 false。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        reach.resize(n, false);

        dfs(0, rooms);
        for (bool r : reach) {
            if (!r) return false;
        }
        return true;
    }
    vector<bool> reach;

    void dfs (int roomNum, vector<vector<int>>& rooms) {
        if (reach[roomNum]) return; // 防止无限递归，爆栈
        reach[roomNum] = true;
        for (int i = 0; i < rooms[roomNum].size(); i++) {
            dfs(rooms[roomNum][i], rooms);
        }
    }
};

int main() {
    vector<vector<int>> rooms1{{1}, {2}, {3}, {}};
    vector<vector<int>> rooms2 = {{1, 3}, {3, 0, 1}, {2}, {0}};
    Solution s;
//    std::cout << s.canVisitAllRooms(rooms1) << std::endl;
    std::cout << s.canVisitAllRooms(rooms2) << std::endl;
    return 0;
}

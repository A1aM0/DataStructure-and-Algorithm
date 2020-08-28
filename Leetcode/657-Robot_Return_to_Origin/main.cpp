/*!
 * @brief 机器人能否返回原点
 *
 * 在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
 * 移动顺序由字符串表示。
 * 字符 move[i] 表示其第 i 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
 * 如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
 *
 * 注意：机器人“面朝”的方向无关紧要。
 * “R” 将始终使机器人向右移动一次，“L” 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) { // 最简单的做法
        int x = 0, y = 0;
        for (char ch : moves) {
            switch (ch) {
                case 'U': y++;break;
                case 'D': y--;break;
                case 'L': x--;break;
                case 'R': x++;break;
            }
        }
        return (x == 0 && y == 0);
    }
    bool judgeCircle2(string moves) { // 字典，哈希表
        unordered_map<char, int> map;
        for (char ch : moves) {
            map[ch]++;
        }
        return (map['U'] == map['D'] && map['L'] == map['R']);
    }
    bool judgeCircle3(string moves) { // for_each+lambda表达式
        unordered_map<char, int> map;
        std::for_each(moves.begin(), moves.end(), [&map](char ch){
            map[ch]++;
        });
        return (map['U'] == map['D'] && map['L'] == map['R']);
    }
};

int main() {
    string move1{"UD"};
    string move2{"LL"};
    Solution s;
    std::cout << s.judgeCircle(move1) << std::endl;
    std::cout << s.judgeCircle(move2) << std::endl;
    std::cout << s.judgeCircle2(move1) << std::endl;
    std::cout << s.judgeCircle2(move2) << std::endl;
    std::cout << s.judgeCircle3(move1) << std::endl;
    std::cout << s.judgeCircle3(move2) << std::endl;
    return 0;
}

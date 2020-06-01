/*!
 * @brief 汉明距离
 *
 * 两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
 * 给出两个整数 x 和 y，计算它们之间的汉明距离。
 *
 * 注意：
 * 0 ≤ x, y < 2^31.
 */

#include <iostream>

class Solution {
public:
    int hammingDistance(int x, int y) { //  XOR 的位运算，当且仅当输入位不同时输出为 1。然后将每个位移动到最左侧或最右侧，然后检查该位是否为 1
        int cnt(0);
        int cmp = x ^ y;
        while (cmp) {
            if (cmp & 1) cnt ++;
            cmp >>= 1;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    std::cout << s.hammingDistance(1, 4) << std::endl;
    return 0;
}

/*!
 * @brief 位1的个数
 *
 * 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。
 */

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt(0);
        while (n) {
            // 将 n 和 n - 1 做与运算，会把最后一个 1 的位变成 0。
            // 在二进制表示中，数字 n 中最低位的 1 总是对应 n - 1 中的 0。
            // 因此，将 n 和 n - 1 与运算总是能把 n 中最低位的 1 变成 0 ，并保持其他位不变。
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};

int main() {
    uint32_t num = 0b00000000000000000000000000001011;
    Solution s;
    std::cout << s.hammingWeight(num) << std::endl;
    return 0;
}

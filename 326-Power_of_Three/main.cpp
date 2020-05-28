/*!
 * @brief 3的幂
 *
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
 */

#include <iostream>

class Solution {
public:
    bool isPowerOfThree(int n) { // int n变量是四个字节，他的最大值为 2147483647，推断出3的幂的最大值，也就是1162261467，只需要将 3^{19}除以n。若余数为0意味着n是 3^{19}的除数，即是3的幂
        return n > 0 && 1162261467 % n == 0;
    }
};

int main() {
    Solution s;
    std::cout << (s.isPowerOfThree(1162261467 / 3) ? "true" : "false") << std::endl;
    return 0;
}

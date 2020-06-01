/*!
 * @brief 颠倒二进制位
 *
 * 颠倒给定的 32 位无符号整数的二进制位。
 */

#include <iostream>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res(0);
        // 如果先加res后对res移位：在最后一轮，res加完已经得到想要的结果了，但是接下来左移，导致结果不正确；
        // 所以先对res(0)左移：0左移还是0，在最后一轮加完之后，就会退出循环
        for (int i = 32; i > 0; i--) {
            res <<= 1;
            res += n & 1;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.reverseBits(0b00000010100101000001111010011100) << std::endl;
    std::cout << s.reverseBits(0b11111111111111111111111111111101) << std::endl;
    return 0;
}

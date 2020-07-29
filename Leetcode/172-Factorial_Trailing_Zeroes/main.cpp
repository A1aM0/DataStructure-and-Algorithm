/*!
 * @brief 阶乘后的零
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) { // 2和5才能组合出一个0，而且2的数量肯定要比5多，只用看5的数量
        int count = 0;
        while (n / 5 != 0) { // 25、125、625是由多个5组成的，所以不能单次除以5作为结果，还需多次除以5
            count += n / 5;
            n = n / 5;
        }
        return count;
    }
};

int main() {
    Solution s;
    std::cout << s.trailingZeroes(31) << std::endl;
    std::cout << s.trailingZeroes(10) << std::endl;
    std::cout << s.trailingZeroes(5) << std::endl;
    std::cout << s.trailingZeroes(3) << std::endl;
    return 0;
}

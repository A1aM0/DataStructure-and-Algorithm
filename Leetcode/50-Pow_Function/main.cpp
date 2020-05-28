/*!
 * @brief Pow(x, n)
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^(31 − 1)] 。
 */

#include <iostream>

class Solution {
public:
    double myPow(double x, int n) {
        // 最蠢的办法就是挨个乘过去
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double res = 1;
        while (n--) {
            res *= x;
        }
        return res;
    }
    double myPow2(double x, int n) {
        // 快速幂算法：
        // 假设已经得到x^n，然后可以快速计算出x^2n，只用乘一次。
        // 二分的思想，时间复杂度是对数级，而上面的是O(n)
        double res = 1.0;
        for (int i = n; i != 0; i /= 2) {
            // 使用折半计算，每次把n缩小一半，这样n最终会缩小到0，任何数的0次方都为1，这时候我们再往回乘。
            // 如果此时n是偶数，直接把上次递归得到的值算个平方返回即可，如果是奇数，则还需要乘上个x的值。
            if (i % 2 != 0) res *= x;
            x *= x;
        }
        return n < 0 ? 1 / res : res;
    }
};

int main() {
    Solution s;
    std::cout << "result is " << s.myPow2(2.00000, 10) << std::endl;
    return 0;
}

/*!
 * @brief 两数相除
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2
 *
 * 提示：
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 */

#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend > INT_MIN) return -dividend;
            return INT_MAX;
        }

        // 用long long 去转的原因是，题目只要求到32位有符号，对应signed int，要进行越界的判断的话，直接转成longlong，
        // 不用long的原因是在64/32位机上，long虽然定义的是32位起，但通常都是32位的，和int就没区别了，而longlong就被定义成64位的，所以用longlong
        long long _dividend = dividend;
        long long _divisor = divisor;
        _dividend = _dividend > 0 ? _dividend : -_dividend;
        _divisor = _divisor > 0 ? _divisor : -_divisor;

        long long res = div(_dividend, _divisor);
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            return res > INT_MAX ? INT_MAX : res;
        }
        else {
            return -res;
        }
    }

    long long int div (long long dividend, long long divisor) {
        // 思路搬运：
        // 首先11比3大，结果至少是1，
        // 然后我让3翻倍，就是6，发现11比3翻倍后还要大，那么结果就至少是2了，
        // 那我让这个6再翻倍，得12，11不比12大，吓死我了，差点让就让刚才的最小解2也翻倍得到4了。
        // 但是我知道最终结果肯定在2和4之间。也就是说2再加上某个数，这个数是多少呢？
        // 我让11减去刚才最后一次的结果6，剩下5，我们计算5是3的几倍，也就是除法，
        // 看，递归出现了。
        if (dividend < divisor) return 0;
        long long tmp = divisor;
        long long count = 1;
        while (tmp + tmp < dividend) {
            count = count + count;
            tmp = tmp + tmp;
        }
        return count + div(dividend - tmp, divisor);
    }
};

int main() {
    Solution s;
    std::cout << s.divide(10 ,3) << std::endl;
    std::cout << s.divide(-7 ,-3) << std::endl;
    return 0;
}

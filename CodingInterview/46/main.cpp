/*!
 * @brief 46-把数字翻译成字符串
 *
 * 给定一个数字，我们按照如下规则把它翻译为字符串：
 * 0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
 * 一个数字可能有多个翻译。
 *
 * 请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
 */

#include <iostream>

class Solution {
public:
    // DP:
    // 我们可以用 f(i) 表示以第 i 位结尾的前缀串翻译的方案数，
    // 考虑第 i 位单独翻译和与前一位连接起来再翻译对 f(i) 的贡献。
    // 单独翻译对 f(i) 的贡献为 f(i−1)；
    // 如果第 i - 1 位存在，并且第 i−1 位和第 i 位形成的数字 x 满足 10≤x≤25，
    // 那么就可以把第 i−1 位和第 i 位连起来一起翻译，对 f(i) 的贡献为 f(i−2)，否则为 0.
    // f(i)=f(i−1)+f(i−2)[i−1≥0,10≤x≤25]
    int translateNum(int num) {
        std::string str = std::to_string(num);
        int last2 = 0, last1 = 0; // 记录前两个、前一个翻译方法数量的临时变量
        int cur = 1; // 记录当前数字翻译方法
        for (int i = 0; i < str.size(); ++i) {
            // last2、last1、cur存的是上轮的结果，需要更新
            last2 = last1;
            last1 = cur;
            cur = 0;

            cur = cur + last1;
            if (i == 0) continue; // 下一行计算tmp的时候用到i-1，所以要先判断i>0
            int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0'); // 本位的数字和上一位组成的两位数
            if (tmp >= 10 && tmp <= 25) {
                cur  = cur + last2;
            }
        }
        return cur;
    }
};

int main() {
    Solution s;

    std::cout << s.translateNum(12258) << std::endl;
    return 0;
}

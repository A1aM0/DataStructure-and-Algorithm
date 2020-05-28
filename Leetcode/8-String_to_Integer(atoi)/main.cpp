/*!
 * @brief 字符串转换整数 (atoi)
 *
 * 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
 * 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
 *
 * 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
 * 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
 * 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
 * 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
 *
 * 在任何情况下，若函数不能进行有效的转换时，请返回 0 。
 *
 * @note
 * 本题中的空白字符只包括空格字符 ' ' 。
 * 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−2^31,  2^31 − 1]。如果数值超过这个范围，请返回  INT_MAX (2^31 − 1) 或 INT_MIN (−2^31) 。
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    static int myAtoi(string str) {
        int index = 0, res = 0;
        bool positive = true;
        while (str[index] == ' ') index++;
        if (str[index] == '-') positive = false;
        if (str[index] == '-' || str[index] == '+') index++;
        while (index < str.size() && isdigit(str[index])) {
            int num = str[index] - '0';
            if (res > INT_MAX / 10 || (res == INT_MAX/10 && num > 7)) return positive ? INT_MAX : INT_MIN;
            res = res * 10 + num;
            index++;
        }
        return positive ? res : -res;
    }
};

int main() {
    string str1 = "42"; // output: 42
    string str2 = "          -42"; // output: -42
    string str3 = "4193 with words"; // output: 4193
    string str4 = "words and 987"; // output: 987
    string str5 = "-91283472332"; // output: -2147483648
    string str6 = "2147483646"; // output: 2147483646

    cout << "result is " << Solution::myAtoi(str6) << endl;
    return 0;
}

/*!
 * @brief 外观数列
 *
 * 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 *
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 *
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * 注意：整数序列中的每一项将表示为一个字符串。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n < 1) return "";
        string res{"1"};
        for (int i = 1; i < n; ++i) {
            res = process(res);
        }
        return res;
    }
    string process(string str) {
        int cnt = 1; // 相同数字连续出现的计数器
        string res;
        for (int i = 0; i < str.size() - 1; i++) {
            if (str[i] == str[i + 1]) cnt++; // 数字连续出现
            else { // 数字不连续出现，cnt为到当前数字连续出现的次数
                res = res + char(cnt + '0'); // 在res后面先跟数字次数，转为char，或者表达式可简写为 res += cnt + '0' ，右边的优先级高，算完之后发生隐式转换为char
                res = res + str[i]; // res跟完次数以后，再跟这个数字
                cnt = 1; // 重置cnt
            }
        }
        res = res + char(cnt + '0'); // 循环里找的是倒数第二个重复的数字，最后又cnt记了一次数，记的是最后一个数字连续出现的次数，像循环里一样加上
        res = res + str[str.size() - 1];
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.countAndSay(4) << std::endl;
    return 0;
}

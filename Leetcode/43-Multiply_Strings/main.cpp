/*!
 * @brief 字符串相乘
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，
 * 返回 num1 和 num2 的乘积，
 * 它们的乘积也表示为字符串形式。
 *
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 */

#include <bits/stdc++.h>
using std::string;
using std::vector;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1[0] == '0' || num2[0] == '0') return "0";
        int len1 = num1.size(), len2 = num2.size();
        vector<int> ans(len1 + len2, 0);
        string res;
        for (int i = len1 - 1; i >= 0; i--) {
            int x = num1[i] - '0';
            for (int j = len2 - 1; j >= 0; j--) {
                int y = num2[j] - '0';
                int pos = i + j + 1;
                ans[pos] = x * y + ans[pos];
                ans[pos - 1] = ans[pos] / 10 + ans[pos - 1];
                ans[pos] %= 10;
            }
        }
        for (int num : ans) {
            res.push_back((char)(num + '0'));
        }
        return res[0] == '0' ? res.substr(1, res.size() - 1) : res;
    }
};

int main() {
    Solution s;
    std::cout << s.multiply("123", "456") << std::endl;
    return 0;
}

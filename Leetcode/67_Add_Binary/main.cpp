/*!
 * @brief 二进制求和
 *
 * @details
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 输入为非空字符串且只包含数字 1 和 0。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aLen = a.size(), bLen = b.size();
        // 补齐a和b的长度，少了就补0
        while (aLen < bLen) {
            a = '0' + a;
            ++aLen;
        }
        while (aLen > bLen) {
            b = '0' + b;
            ++bLen;
        }
        //从末位开始相加，直到正数第二位
        for (int i = a.size() - 1; i > 0; --i) {
            a[i] = a[i] - '0' + b[i]; // a作为被加数，直接被b加就行
            // 进位
            if(a[i] >= '2') {
                a[i] = '0' + (a[i] - '0') % 2;
                a[i - 1] = a[i - 1] + 1;
            }
        }
        // 加最高位
        a[0] = a[0] + b[0] - '0';
        // 检查进位
        if (a[0] >= '2') {
            a[0] = '0' + (a[0] - '0') % 2;
            a = '1' + a; // 直接给前面补1
        }
        return a;
    }
};

int main() {
    string a = "1010", b = "1011";
    Solution s;
    cout << s.addBinary(a, b);
    return 0;
}
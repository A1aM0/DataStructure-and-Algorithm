/*!
 * @brief 最长公共前缀
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 * @warning
 * 所有输入只包含小写字母 a-z 。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        if (strs.size() == 1) return strs[0];

        string result = {};
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 0; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) return result; ///< 检查后面的每一个字符串的第i位是否与第一个相同，不同则第i位已经不是公共前缀了
            }
            result += strs[0][i];
        }
        return result;
    }
};

int main() {
    vector<string> str = {"flower","flow","flight"};
    vector<string> str2 = {"dog","racecar","car"};
    Solution s;

    cout << s.longestCommonPrefix(str2);
    return 0;
}
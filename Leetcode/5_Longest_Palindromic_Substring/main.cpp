/*!
 * @brief 最长回文子串
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*!
     * @details
     * 思路：双指针。寻找回文串：从中间向两边找。需要区分两种情况，一个是i号为中心的，一种是i与i+1号为中心的。
     *
     * @param s 待查询的字符串
     * @return 最长回文子串
     */
    string longestPalindrome(string s) {
        string res; ///< 存储结果
        for(int i = 0; i < s.length(); ++i) {
            string str1 = judgePalindrome(s, i, i);
            string str2 = judgePalindrome(s, i, i+1);
            res = res.length() > str1.length() ? res : str1;
            res = res.length() > str2.length() ? res : str2;
        }
        return res;
    }

    /*!
     * 判断回文
     * @param s 原始字符串
     * @param left 起始位置及左边的位置
     * @param right 起始位置及右边的位置
     * @return 以某位置为中心的最长回文串
     */
    string judgePalindrome(string s, int left, int right) {
        /// 防索引越界，left最小为0，right不大于最大索引值
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            --left;
            ++right;
        }
        /// 返回边界为left和right的子串，left和right在while循环里被多运算了一遍
        return s.substr(++left, right - left - 1);
    }

    string longestPalindrome2(string s) { // 官方题解搬运，DP
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }

                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};

int main() {
    string str1 = "babad";
    string str2 = "cbbd";

    Solution s;
    cout << s.longestPalindrome(str2);
    return 0;
}
/**
 * @brief  验证回文字符串 Ⅱ
 * 
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 */

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        bool flag = false;
        while (i < j) {
            if (s[i] != s[j]) {
                return validPalindrome(s, i + 1, j) || validPalindrome(s, i, j - 1);
            }
            ++i;
            --j;
        }
        return true;
    }
    bool validPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

/*!
 * @brief 验证回文字符串
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 */

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i <= j;) {
            if (!isalpha(s[i]) && !isdigit(s[i])) {
                ++i;
                continue;
            }
            if (!isalnum(s[j])) {
                --j;
                continue;
            }
            if ((s[i] | 0x20) != (s[j] | 0x20)) return false; // 转小写还有tolower()，或者转大写比较 (ch & 0xDF)
            ++i;
            --j;
        }
        return true;
    }
};

int main() {
    string s{"A man, a plan, a canal: Panama"};
//    string s{"race a car"};
    Solution so;
    std::cout << "result is " << (so.isPalindrome(s) ? "true" : "false") << std::endl;
    return 0;
}

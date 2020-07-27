/*!
 * @brief 判断子序列
 *
 * 给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
 *
 * 你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
 * 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
//        if (s.empty()) return true;
//        int i = 0, j = 0;
//        while (i < s.size() && j < t.size()) {
//            if (s[i] == t[j]) {
//                i++;
//                j++;
//            }
//            else j++;
//            if (i >= s.size()) return true;
//        }
//        return false;
        // 一个改进
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};

int main() {
    string t{"ahbgdc"};
    string s{"abc"};
    Solution so;
    std::cout << so.isSubsequence(s, t) << std::endl;
    return 0;
}

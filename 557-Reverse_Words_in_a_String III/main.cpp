/*!
 * @brief 反转字符串中的单词 III
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 *
 * @warning 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static string reverseWords(string s) {
        string res = "", word = "";
        for (int begin = 0; begin <= s.size(); ++begin) {
            if (s[begin] == ' ' || s[begin] == '\0') { // 检测空格或者字符串结束符，将前面已经遍历的认为是一个单词，反转
                reverse(word.begin(), word.end());
                res += word; // 反转后的单词加到结果上
                res += s[begin]; // 再把这个空格或者结束符加到结果上去
                word = ""; // 重置单词字符串
            } else {
                word += s[begin]; // 拼接单词
            }
        }
        return res;
    }

    static string reverseWords2(string s) { // 思路和上面差不多，用两个指针直接表示单词的首尾，随后原地翻转
        int i = 0, j = 0;
        for (int n = 0; n < s.size(); n++) {
            if (s[n] != ' ') ++j;
            else {
                reverse(s.begin()+i, s.begin()+j);
                i = ++j;
            }
        }
        reverse(s.begin()+i, s.begin()+j);
        return s;
    }
};

int main() {
    string str = "Let's take LeetCode contest"; // output is: "s'teL ekat edoCteeL tsetnoc"

    cout << Solution::reverseWords2(str) << endl;
    return 0;
}

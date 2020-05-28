/*!
 * @brief  字符串解码
 *
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 */

#include <iostream>
#include <stack>

class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<std::string> sk;
        std::stack<int> times;
        std::string str;
        for (int i = 0; i < s.size(); ) {
            char ch = s[i];
            if (isdigit(ch)) {
                times.push(stoi(getTimes(s, i)));
            } else if (isalpha(ch)) {
                str += ch;
                ++i;
            } else if (ch == '[') {
                sk.push(str);
                str.clear();
                ++i;
            } else {
                int time = times.top();
                times.pop();
                while (time--) sk.top() += str;
                str = sk.top();
                sk.pop();
                ++i;
            }
        }
        return str;
    }

private:
    std::string getTimes (std::string s, int &pos) {
        std::string times;
        while (isdigit(s[pos])) {
            times.push_back(s[pos++]);
        }
        return times;
    }
};

int main() {
//    std::string s{"3[a]2[bc]"}; // "aaabcbc"
//    std::string s{"3[a2[c]]"}; // "accaccacc"
    std::string s{"2[abc]3[cd]ef"}; // "abcabccdcdcdef"
    Solution so;
    std::cout << so.decodeString(s) << std::endl;
    return 0;
}

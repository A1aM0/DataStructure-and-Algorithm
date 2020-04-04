/*!
 * @brief 有效的括号
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 有效字符串需满足：
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 注意空字符串可被认为是有效字符串。
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    static bool isValid(string s) {
        stack<char> leftParenthesis;
        // 左括号入栈，遇到右括号则将与栈顶比较能否闭合，最后看栈是否为空
        for (char tmp : s) {
            if (leftParenthesis.empty()) leftParenthesis.push(tmp); // 防止单独出现右括号，若出现则会被入栈，最后结果必为false
            else if (tmp == ')' && '(' == leftParenthesis.top()) leftParenthesis.pop();
            else if (tmp == ']' && '[' == leftParenthesis.top()) leftParenthesis.pop();
            else if (tmp == '}' && '{' == leftParenthesis.top()) leftParenthesis.pop();
            else leftParenthesis.push(tmp); // 其余情况均为左括号，因为str里除了右括号就是左括号，没有别的字符
        }
        return leftParenthesis.empty();
    }
};

int main() {
    string str1 = "()";
    string str2 = "()[]{}";
    string str3 = "(]";
    string str4 = "([)]";
    string str5 = "{[]}";
    string str6 = "]";
    cout << "result is " << Solution::isValid(str1) << endl;
    cout << "result is " << Solution::isValid(str2) << endl;
    cout << "result is " << Solution::isValid(str3) << endl;
    cout << "result is " << Solution::isValid(str4) << endl;
    cout << "result is " << Solution::isValid(str5) << endl;
    cout << "result is " << Solution::isValid(str6) << endl;
    return 0;
}

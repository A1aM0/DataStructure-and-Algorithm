/*!
 * @brief  最长有效括号
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res(0);
        stack<int> sk;
        sk.push(-1); // 放一个-1，当做第一个右括号的下标是-1，为了保证栈里面总是有“最后一个没有被匹配的右括号的下标”
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') sk.push(i); // (，将它的下标放入栈中
            else { // 遇到 )
                sk.pop(); //先弹出栈顶元素表示匹配
                if (sk.empty()) {
                    sk.push(i);
                    // 如果栈为空，说明当前的右括号为没有被匹配的左括号，
                    // 因为按理说应该有一个前面多余的右括号')'作为边界，但是被pop了，
                    // 所以需要把遍历到的这个右括号放到栈里作为新的边界
                } else {
                    res = max(res, i - sk.top());
                }
            }
        }
        return res;
    }

};

int main() {
//    string str{"(()"};
//    string str{")()())"};
    string str{"()(())))())"};
    Solution s;
    std::cout << s.longestValidParentheses(str) << std::endl;
    return 0;
}

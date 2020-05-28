/*!
 * @brief 逆波兰表达式求值
 *
 * 根据逆波兰表示法，求表达式的值。
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *
 * @note
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string str : tokens) {
            if (str == "+" || str == "-" ||str == "*" ||str == "/") {
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                if (str == "+") stk.push(left + right);
                else if (str == "-") stk.push(left - right);
                else if (str == "*") stk.push(left * right);
                else if (str == "/") stk.push(left / right);
            } else {
                stk.push(stoi(str)); // 通过stl直接把str转成了int，也可以自己实现atoi()
            }
        }
        return stk.top();
    }
};

int main() {
    vector<string> str1 = {"2", "1", "+", "3", "*"}; // ((2 + 1) * 3) = 9
    vector<string> str2 = {"4", "13", "5", "/", "+"}; // (4 + (13 / 5)) = 6
    vector<string> str3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}; // ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 = 22
    vector<string> str4 = {"4","13","5","/","+"};
    Solution s;
    cout << "result is " <<  s.evalRPN(str4) << endl;
    return 0;
}

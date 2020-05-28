/*!
 * @brief 括号生成
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 *
 * @example
 * 输入：n = 3;
 * 输出：["((()))", "(()())", "(())()", "()(())", "()()()"].
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        /*
         * 第一反应应该是递归，先放一对括号进去之后，剩下应该是接着调用生成的函数，相当于generateParenthesis(int n-1)......
         * n一直减下去，直至0。
         * 但实际上思路只能是说“像”，用dfs。
         */
        dfs(n, n, "");
        return res;
    }
private:
    void dfs(int left, int right, string curStr) {
        if (left == 0 && right == 0) {
            res.push_back(curStr);
            return;
        }

        if (left > 0) {
            dfs(left - 1, right, curStr + "(");
        }

        if (right > left) {
            dfs(left, right - 1, curStr + ")");
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for (string str : res) {
        cout << str << endl;
    }
    return 0;
}

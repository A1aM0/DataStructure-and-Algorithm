/*!
 * @brief 电话号码的字母组合
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 可以任意选择答案输出的顺序。
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    unordered_map<char, string> map {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> res;
    string tmp;

    vector<string> letterCombinations(string digits) { // 本质上是多叉树的遍历，遍历过程比较像二叉树的先序
        if (digits.empty()) return {};
        dfs(0, digits);
        return res;
    }

    void dfs(int index, string digits) {
        if (index == digits.size()) {
            res.push_back(tmp);
            return;
        }
        char ch = digits[index];
        for (int i = 0; i < map[ch].size(); i++) {
            tmp += map[ch][i];
            dfs(index + 1, digits);
            tmp.pop_back(); // 当前路径找完了，回溯到没加入这个点之前的状态
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for (string str : res) {
        std::cout << str << std::endl;
    }
    return 0;
}

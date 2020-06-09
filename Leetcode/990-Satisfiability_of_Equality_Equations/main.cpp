/*!
 * @brief 等式方程的可满足性
 *
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一：
 * "a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
 *
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; i++) arr[i] = i;

        for (string str : equations) {
            if (str[1] == '=') {
                int x = find(str[0] - 'a');
                int y = find(str[3] - 'a');
                if (x != y) arr[x] = y;
            }
        }
        for (string str : equations) {
            if (str[1] == '!') {
                int x = find(str[0] - 'a');
                int y = find(str[3] - 'a');
                if (x == y) return false;
            }
        }
        return true;
    }

private:
    int arr[26]; // 记录26个字母的上级是谁

    int find(int x) { // 找根结点
        int father = x; // 临时记x的上级就是他自己
        while (arr[father] != father) father = arr[father]; // 检查x的上级是不是自己，是自己的话就找到根了，不是的话继续往上找
        return father;
    }

    void join(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) arr[fx] = fy;
    }
};

int main() {
//    vector<string> equations{"a==b","b!=a"}; // F
//    vector<string> equations{"b==a","a==b"}; // T
//    vector<string> equations{"a==b","b==c","a==c"}; // T
//    vector<string> equations{"a==b","b!=c","c==a"}; // F
    vector<string> equations{"c==c","b==d","x!=z"}; // T
    Solution s;
    std::cout << (s.equationsPossible(equations) ? "true" : "false") << std::endl;
    return 0;
}

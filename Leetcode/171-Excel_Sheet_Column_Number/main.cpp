/*!
 * @brief Excel表列序号
 *
 * 给定一个Excel表格中的列名称，返回其相应的列序号。
 *
 * 例如，
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28
 * ...
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) { // 相当于26进制转10进制
        int col = 0;
        for (char letter : s) {
            col = col * 26 + (letter - 'A') + 1;
        }
        return col;
    }
};

int main() {
    Solution s;
    std::cout << s.titleToNumber("AA") << std::endl;
    return 0;
}

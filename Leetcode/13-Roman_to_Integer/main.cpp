/*!
 * @brief 罗马数字转整数
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 *
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 *
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。
 * 这个特殊的规则只适用于以下六种情况：
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 *
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 */

#include <iostream>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) { // 明确一点：一个长罗马数是按照从左往右从大到小罗列的，例外情况是4,9等，但总体也算符合从大到小，例如400(CD)在100(C)左边
        std::unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - 1) {
                sum += m[s[i]];
                continue;
            }
            char cur = s[i];
            char next = s[i + 1];
            if (m[cur] < m[next]) sum -= m[cur]; // 当前与下一位比较，若小，则这是一个组合的罗马数，例如4,9，等，可以直接在sum上减去
            else sum += m[cur];
        }
        return sum;
    }
};

int main() {
//    std::string str{"MCMXCIV"};
//    std::string str{"III"};
//    std::string str{"IV"};
    std::string str{"LVIII"};
    Solution s;
    std::cout << s.romanToInt(str) << std::endl;
    return 0;
}

/*!
 * @brief 分数到小数
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母 denominator，以字符串形式返回小数。
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 */

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) return ""; // 分母为0
        if (numerator == 0) return "0"; // 分子为0

        string res;

        long long _numerator = numerator; // 转成longlong，防止把负数转成正数的时候 INT_MIN=-2^31 会超出 INT_MAX=2^31-1 的范围，以及long一般也是32位的，和int一样，还是转成64位的longlong保险
        long long _denominator = denominator;
        if (_numerator * _denominator < 0) res.append("-"); // 判断结果的正负号

        _numerator = _numerator > 0 ? _numerator : -_numerator; // 把两个数都变成正数，便于计算，这里用到longlong的64位的特点
        _denominator = _denominator > 0 ? _denominator : -_denominator;

        res.append(to_string(_numerator / _denominator)); // 先把结果整数部分直接放进去
        _numerator = _numerator % _denominator; // 除数值变成了余数， 继续做除法（列竖式计算的流程）

        if (_numerator == 0) return res; // 判断整除了可以直接返回
        res.append("."); // 否则就加小数点，继续对除数做除法

        unordered_map<int, int> map; // 用哈希表记录余数出现的情况，当重复的时候，意味着循环开始了
        int index = res.size() - 1; // 记录小数点后小数的位数，作为哈希中的value
        while (_numerator && map.count(_numerator) == 0) {
            map[_numerator] = ++index;
            _numerator *= 10;
            res.append(to_string(_numerator / _denominator));
            _numerator %= _denominator;
        }
        if (map.count(_numerator) == 1) { // 补括号
            res.insert(map[_numerator], "(");
            res.append(")");
        }
        return res;
    }
};

int main() {
    Solution s;
    std::cout << s.fractionToDecimal(1, 2) << std::endl;
    std::cout << s.fractionToDecimal(2, 1) << std::endl;
    std::cout << s.fractionToDecimal(2, 3) << std::endl;
    return 0;
}

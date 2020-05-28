/*!
 * @brief Fizz Buzz
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 */

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) { // 愚蠢的暴力法，仅适用于条件较少的情况，如果条件多起来，需要考虑更多的公倍数的情况
        std::vector<std::string> res;
        for (int i = 1; i <= n; ++i) {
            if (i % 15 == 0) res.push_back("FizzBuzz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else res.push_back(std::to_string(i));
        }
        return res;
    }
    std::vector<std::string> fizzBuzz2(int n) { // 字符串拼接
        std::vector<std::string> res(n);
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) res[i - 1] += "Fizz";
            if (i % 5 == 0) res[i - 1] += "Buzz";
            if (res[i - 1] == "") res[i - 1] += std::to_string(i);
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<std::string> res = s.fizzBuzz2(15);
    for (std::string str : res) std::cout << str << " ";
    return 0;
}

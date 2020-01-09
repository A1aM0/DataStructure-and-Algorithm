/*!
 * @brief 整数反转
 *
 * @details
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 */
#include <iostream>

class Solution {
public:
    static int reverse(int x) {
        int result = 0, tmp;
        // if(x < 10 || (x + 10) < 10) return x;
        while(x / 10 || x % 10){
            tmp = x % 10;
            if(result > INT_MAX / 10 || result < INT_MIN / 10) return 0;
            result = result * 10 + tmp;
            x = (x - tmp) / 10;
        }
        return result;
    }
};

int main() {
    int num = 123; // output is 321
//    int num = -123; // output is -321
//    int num = 120; // output is 21
    std::cout << "result is " << Solution::reverse(num) << std::endl;
    return 0;
}

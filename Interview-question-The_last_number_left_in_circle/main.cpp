/*!
 * @brief 圆圈中最后剩下的数字
 *
 * 0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。
 * 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
 */

#include <iostream>

class Solution {
public:
    static int lastRemaining(int n, int m) {
        // 约瑟夫环问题，可百度
        // 主要逆推最后留下的数字，在每一轮中的实际位置
        int remainingPosition = 0;
        for (int i = 2; i <= n; i++) {
            remainingPosition = (remainingPosition + m) % i;
        }
        return remainingPosition;
    }
};

int main() {
    std::cout << "Result is " << Solution::lastRemaining(5,3) << std::endl;
    return 0;
}

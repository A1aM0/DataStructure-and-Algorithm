/*!
 * @brief 求1+2+…+n
 *
 * 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
 */

#include <iostream>

class Solution {
public:
    int sumNums(int n) { // 递归代替for循环，用 && 代替 if 语句判断 n==0
         int sum = n;
         n && (sum = sum + sumNums(n - 1));
         return sum;
    }
    int sumNums2(int n) { // 高斯公式，但是借助数组的大小，直接得到 n*(n+1) 的值，最后右移代替除以2
        char arr[n][n + 1]; //或者是bool型的数组都行
        return sizeof(arr) >> 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

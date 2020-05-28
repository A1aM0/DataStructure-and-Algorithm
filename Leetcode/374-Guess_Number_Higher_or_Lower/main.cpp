/*!
 * @brief 猜数字大小
 * 我们正在玩一个猜数字游戏。 游戏规则如下：
 * 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
 * 每次你猜错了，我会告诉你这个数字是大了还是小了。
 *
 * 你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
 * -1 : 我的数字比较小
 * 1 : 我的数字比较大
 * 0 : 恭喜！你猜对了！
 */

#include <iostream>

class Solution {
public:
    int guessNumber(int n) {
        long int left = 1, right = n; // 用long的原因是 (l + r) 可能越界，也可以用int然后在计算mid的时候改为 mid = left + (right - left) / 2
        while (left <= right) {
            int mid = (int)((left + right) / 2);
            if (guess(mid) == 1) left = mid + 1;
            else if (guess(mid) == -1) right = mid - 1;
            else if (guess(mid) == 0) return mid;
        }
        return left;
    }

private:

    int guess(int num) {
        //
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

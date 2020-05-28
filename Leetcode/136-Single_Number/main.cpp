/*!
 * @brief 只出现一次的数字
 *
 * @details
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 *
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int singleNumber(vector<int>& nums) { // 时间复杂度O(n)与空间复杂度O(1)单个实现起来较为简单，主要难在结合
        // 异或的方法：
        // 一个数 XOR 0 的结果是本身，一个数 XOR 它自己结果为0
        // 异或满足交换律和结合律，即 a xor b xor a = a xor a xor b
        // 因此，遍历地异或一遍数组，就可以得到只有一个的数
        // 另一个关键是，题目指出了重复出现的数，出现的次数是一次，这点很关键
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res = nums[i] ^ res;
        }
        return res;
    }
};

int main() {
    vector<int> nums = {2, 2, 1}; // output: 1
//    vector<int> nums = {4, 1, 2, 1, 2}; // output: 4
    cout << "result is " << Solution::singleNumber(nums) << endl;
    return 0;
}

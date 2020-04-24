/*!
 * @brief 寻找重复数
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 *
 * 说明：
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 暴力时间超出O(n^2)。
        // 先排序，再用时间为O(n)逐个对比，要么改变原数组，要么空间不为O(1)。
        // 快慢指针的思想是基于查找循环链表入口的方法，但是需要一些额外的数学证明找到环的入口。

        // 二分比较好理解：审题，可知在n+1个数里，必有1~n这n个自然数，然后多了某个重复的数。
        // 不用从下标的0~n-1取，直接二分自然数的值1~n。=> left=1，right为nums数量减1，[left, right]就囊括了数字1~n。
        int left = 1, right = nums.size() - 1;
        while (left < right) {
            // 二分，取区间的中位数，轮训数组找比中位数小的数字的数量
            int mid = left + (right - left + 1) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num < mid) cnt++;
            }

            // 理论上，在1~n中，若取一个参照x，则小于x的数字的数量必为x-1。
            // 若成立，则说明多余的重复数是在比中位数更大的那些数里。因为cnt++的条件不包括重复数就是mid，所以left只能更新为mid。
            if (cnt < mid) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1,3,4,2,2};
    Solution s;
    std::cout << "result is " << s.findDuplicate(nums) << std::endl;
    return 0;
}

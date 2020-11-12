/*!
 * @brief 按奇偶排序数组 II
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
 * 你可以返回任何满足上述条件的数组作为答案。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // 不原地的算法：
        // 遍历一遍数组把所有的偶数放进 ans[0]，ans[2]，ans[4]，依次类推。
        // 再遍历一遍数组把所有的奇数依次放进 ans[1]，ans[3]，ans[5]，依次类推。

        // 原地算法。
        // 为数组的偶数下标部分和奇数下标部分分别维护指针 i, j。
        // 随后，在每一步中，如果 A[i] 为奇数，则不断地向前移动 j（每次移动两个单位），
        // 直到遇见下一个偶数。此时，可以直接将 A[i] 与 A[j] 交换。
        // 我们不断进行这样的过程，最终能够将所有的整数放在正确的位置上。
        int i = 0, j = 1;
        for (; i < A.size(); i += 2) {
            if (A[i] % 2 == 1) {
                while (A[j] % 2 == 1) {
                    j += 2;
                }
                swap(A[i], A[j]);
            }
        }
        return A;
    }
};

int main() {
    vector<int> nums{4, 2, 5, 7}; // [4,5,2,7], [4,7,2,5]，[2,5,4,7]，[2,7,4,5]
    Solution s;
    vector<int> res = s.sortArrayByParityII(nums);
    for (int n : res) cout << n << " ";
    cout << endl;
    return 0;
}

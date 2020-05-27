/*!
 * @brief 和可被 K 整除的子数组
 *
 * 给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
 *
 * 提示：
 * 1 <= A.length <= 30000
 * -10000 <= A[i] <= 10000
 * 2 <= K <= 10000
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& A, int K) { // 子数组的和——首先想到前缀和。其次，sum(i, j)想被K整除，那么只要pre[i-1]和pre[j]的余数相同就行了，所以可以在统计前缀和的时候计算其余数保存下来
        std::vector<int> mod(K, 0); // 前缀和与K的余数的数量
        int sum(0); // 记录上一个数的前缀和
        mod[0] = 1; // ???不加就错，暂时未知
        for (int i = 0; i < A.size(); i++) {
            sum += A[i];
            mod[(sum % K + K) % K]++;
        }
        int cnt = 0;
        for (int i = 0; i < K; i++) {
            // 假设前缀和余数为4的有3个，那么找出这三个能形成几个子数组，用C^2_3，即三选二（组合）
            // 不考虑数量为1或者0，因为除以2取整之后，就是0
            cnt += mod[i] * (mod[i] - 1) / 2;
        }
        return cnt;
    }
};

int main() {
    std::vector<int> nums{4,5,0,-2,-3,1};
    Solution s;
    std::cout << s.subarraysDivByK(nums, 5) << std::endl;
    return 0;
}

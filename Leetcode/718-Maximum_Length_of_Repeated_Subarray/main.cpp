/*!
 * @brief 最长重复子数组
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 *
 * 说明:
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * 倒着思考： 就以A{1,2,3}B{1,2,4}为例
     * 如果A[1]==B[1]，代表着A[2]和B[2]这两个数字有相同的前缀，同样的对于dp[1][1]，最起码值为1。
     * dp[1][1]会不会更大呢？那就需要看A[2]和B[2]的值是否相等了，以及以A[2]和B[2]为子数组起始的重复子数组的长度，其实就是dp[1][1]=dp[1+1][1+1]+1。
     * 综上，需要一个M*N的矩阵dp，每个位置dp[i][j]记录着以两个数组对应位置作为重复子数组的长度。
     * 转移方程可以写成 if(A[i]==B[j]) dp[i][j]=dp[i+1][j+1]+1。
     * 再考虑边界，dp矩阵里每个位置都要看他右下角位置的数值，所以矩阵应该在初始化的时候再增加一行一列，值为0，方便计算当i最大或者j最大的时候的dp。
     */
    int findLength(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res(0);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (A[i] == B[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
                res = res > dp[i][j] ? res : dp[i][j];
            }
        }
        return res;
    }
};

int main() {
    vector<int> A = {1,2,3,2,1};
    vector<int> B = {3,2,1,4,7};
    Solution s;
    std::cout << s.findLength(A, B) << std::endl;
    return 0;
}

/**
 * @brief 四数相加 II
 * 
 * 给定四个包含整数的数组列表 A , B , C , D ,计算有多少个元组 (i, j, k, l) ，使得 A[i] + B[j] + C[k] + D[l] = 0。
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，且 0 ≤ N ≤ 500 。所有整数的范围在 -2^28 到 2^28 - 1 之间，最终结果不会超过 2^31 - 1 。
 */

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) { // O(n^2)，相较于暴力的O(n^4)好很多了
        unordered_map<int, int> m;
        int res = 0;
        for (int a : A) {
            for (int b : B) {
                m[a + b]++;
            }
        }
        for (int c : C) {
            for (int d : D) {
                res += m[-(c + d)];
            }
        }
        return res;
    }
};

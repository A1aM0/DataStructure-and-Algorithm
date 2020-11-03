/*!
 * @brief 有效的山脉数组
 *
 * 给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。
 * 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
 *
 * A.length >= 3
 * 在 0 < i < A.length - 1 条件下，存在 i 使得：
 * A[0] < A[1] < ... A[i-1] < A[i]
 * A[i] > A[i+1] > ... > A[A.length - 1]
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        int i = 0, j = A.size() - 1;
        while (i < A.size() - 1 && A[i] < A[i + 1]) i++;
        while (j > 0 && A[j] < A[j - 1]) j--;
        return i == j && i != 0 && j != A.size() - 1;
    }
};

int main() {
    Solution s;
    vector<int> A1 = {2, 1};
    vector<int> A2 = {3, 5, 5};
    vector<int> A3 = {0,3,2,1};
    std::cout << s.validMountainArray(A1) << std::endl;
    std::cout << s.validMountainArray(A2) << std::endl;
    std::cout << s.validMountainArray(A3) << std::endl;
    return 0;
}

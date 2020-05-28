/*!
 * @brief 合并排序的数组
 *
 * 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。
 * 初始化 A 和 B 的元素数量分别为 m 和 n。
 *
 * 示例:
 *
 * 输入:
 * A = [1,2,3,0,0,0], m = 3
 * B = [2,5,6],       n = 3
 *
 * 输出: [1,2,2,3,5,6]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static void merge(vector<int>& A, int m, vector<int>& B, int n) {
        // 三个思路，
        // 1. 先把两个数组合到一起，再用排序法，时间空间依选择的排序法而定
        // 2. 从头依次比较，较小的依次填入新的数组中。直到结束，时间O(m+n)，空间O(m+n)。
        // 2（补）. 要是用标准库里的vector.insert的话，空间也可以为O(1)
        // 3. 从后向前比较，较大的可以直接填到A的尾部，时间O(m+n)，空间O(1)
        int p = m-1, q = n-1, i = m+n-1;
        while (p >= 0 || q >=0) {
            if (q < 0) A[i--] = A[p--];
            else if (p < 0) A[i--] = B[q--];
            else if (A[p] >= B[q]) A[i--] = A[p--];
            else A[i--] = B[q--];
        }
    }
};

int main() {
    vector<int> vec1 = {1,2,3,0,0,0};
    vector<int> vec2 = {2,5,6};
    Solution::merge(vec1, vec1.size()-vec2.size(), vec2, vec2.size());
    for (int i = 0; i < vec1.size(); ++i) {
        cout << vec1[i] << " ";
    }
    return 0;
}

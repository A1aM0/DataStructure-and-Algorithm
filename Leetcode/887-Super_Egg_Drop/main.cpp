/*!
 * @brief 鸡蛋掉落
 *
 * 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。
 * 你的目标是确切地知道 F 的值是多少。
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) { // dp的思想，状态矩阵使用递归法去更新
        vector<vector<int>> arr(K + 1, vector<int>(N + 1, -1));
        return dp(arr, K, N);
    }

    // 状态可以表示成 (K, N)，其中 K 为鸡蛋数，N 为楼层数。当我们从第 X 楼扔鸡蛋的时候：
    // 如果鸡蛋不碎，那么状态变成 (K, N-X)，即我们鸡蛋的数目不变，但答案只可能在上方的 N-X 层楼了。
    // 也就是说，我们把原问题缩小成了一个规模为 (K, N-X) 的子问题；
    // 如果鸡蛋碎了，那么状态变成 (K-1, X-1)，即我们少了一个鸡蛋，但我们知道答案只可能在第 X 楼下方的 X−1 层楼中了。
    // 也就是说，我们把原问题缩小成了一个规模为 (K-1, X-1) 的子问题。
    // 对于 dp(K, N) 而言，我们像上面分析的那样，枚举第一个鸡蛋扔在的楼层数 X。
    // 由于我们并不知道真正的 F 值，
    // 因此我们必须保证 "鸡蛋碎了之后接下来需要的步数" 和 "鸡蛋没碎之后接下来需要的步数" 二者的 "最大值" 最小，
    // 这样就保证了在 最坏情况下（也就是无论 FF 的值如何）dp(K, N)的值最小。
    // 如果能理解这一点，也就能理解上面的状态转移方程，
    // 即最小化 max(dp(K-1, X-1), dp(K, N-X))。
    int dp (vector<vector<int>> &arr, int K, int N) {
        if (arr[K][N] == -1) {
            if (N == 0) arr[K][N] = 0; // 0层的情况
            else if (K == 1) arr[K][N] = N; // 只有一个鸡蛋，只能从最底下一层扔起
            else { // 寻找dp(K−1,X−1)和dp(K,N−X)之间的最大值，并找这些最大值里的最小值
                int left = 1, right = N;
                while (left + 1 < right) { // 二分法，找到对应的X
                    int mid = (left + right) >> 1;
                    int x1 = dp(arr, K - 1, mid - 1);
                    int x2 = dp(arr, K, N - mid);

                    if (x1 <= x2) left = mid;
                    else if (x1 > x2) right = mid;
                }

                // 更新dp矩阵
                arr[K][N] = 1 + min(
                        max(dp(arr, K - 1, left - 1), dp(arr, K, N - left)),
                        max(dp(arr, K - 1, right - 1), dp(arr, K, N - right)));
            }
        }
        return arr[K][N];
    }
};

class Solution2 { // 大神解法
    int calcF(int K, int T)
    {
        if (T == 1 || K == 1) return T + 1;
        return calcF(K - 1, T - 1) + calcF(K, T - 1);
    }

    int superEggDrop(int K, int N)
    {
        int T = 1;
        while (calcF(K, T) < N + 1) T++;
        return T;
    }
};

int main() {
    Solution s;
    std::cout << s.superEggDrop(1, 2) << std::endl; // 2
    std::cout << s.superEggDrop(2, 6) << std::endl; // 3
    std::cout << s.superEggDrop(2, 100) << std::endl; // 14
    std::cout << s.superEggDrop(3, 14) << std::endl; // 4
    return 0;
}

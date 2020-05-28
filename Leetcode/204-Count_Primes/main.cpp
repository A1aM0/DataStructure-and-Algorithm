/*!
 * @brief 计数质数
 *
 * 统计所有小于非负整数 n 的质数的数量。
 */

#include <iostream>
#include <vector>

class Solution {
public:
    int countPrimes(int n) { // 暴力，O(n^2)
        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrime(i)) count++;
        return count;
    }
    bool isPrime(int n) {
//        for (int i = 2; i < n; i++)
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    // 用一个数组对所有数字做标记，当找到一个素数的时候，其倍数都可以排除，最后统计标记为true的数量——厄拉多塞筛法(Eratosthenes sieve)
    int countPrimes2(int n) {
        std::vector<bool> prime(n, true);
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                for (int j = 2; j * i < n; j++) {
                    prime[j * i] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; ++i) if (prime[i]) cnt++;
        return cnt;
    }

    // 2的优化，缩小了两层循环的截止条件，省去较多的重复赋false的操作，O(n·log(log n))，需一定数学证明
    int countPrimes3(int n) {
        std::vector<bool> prime(n, true);
        for (int i = 2; i * i < n; i++) {
            if (prime[i]) {
                for (int j = i; j * i < n; j++) {
                    prime[j * i] = false;
                }
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; ++i) if (prime[i]) cnt++;
        return cnt;
    }
};

int main() {
    Solution s;
    int n = 100000;
    std::cout << s.countPrimes(n) << std::endl;
    std::cout << s.countPrimes2(n) << std::endl;
    std::cout << s.countPrimes3(n) << std::endl;
    return 0;
}

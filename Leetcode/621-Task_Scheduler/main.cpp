/*!
 * @brief 任务调度器
 *
 * 给定一个用字符数组表示的 CPU 需要执行的任务列表。
 * 其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。
 * 任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。
 * CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
 * 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，
 * 因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
 *
 * 你需要计算完成所有任务所需要的最短时间。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 参考题解桐梓思想:https://leetcode-cn.com/problems/task-scheduler/solution/tong-zi-by-popopop/
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> bucket(26);
        for (char task : tasks) {
            bucket[task - 'A']++;
        }
        sort(bucket.begin(), bucket.end(), [](int &a, int &b) {
            return a > b;
        });
        int cnt = 1;
        for (int i = 1; i < bucket.size(); i++) {
            if (bucket[i] == bucket[0]) cnt++;
        }
        int a = tasks.size(), b = cnt + (n + 1) * (bucket[0] - 1);
        return max(a, b);
    }
};

int main() {
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    Solution s;
    std::cout << s.leastInterval(tasks, 2) << std::endl;
    return 0;
}

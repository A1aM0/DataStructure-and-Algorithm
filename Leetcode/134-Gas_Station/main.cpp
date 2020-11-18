/*!
 * @brief 加油站
 *
 * 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
 * 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。
 * 你从其中的一个加油站出发，开始时油箱为空。
 * 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
 *
 * 说明:
 * 如果题目有解，该答案即为唯一答案。
 * 输入数组均为非空数组，且长度相同。
 * 输入数组中的元素均为非负数。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        // 首先如果总油量减去总消耗大于零那么一定可以跑完一圈，说明 各个站点的加油站 剩油量remain[i]相加一定是大于零的。
        // 每个加油站的剩余量remain[i]为gas[i] - cost[i]。
        // i从0开始累加remain[i]，和记为curSum，如果curSum小于零，
        // 说明 [0, i]区间都不能作为起始位置，起始位置从i+1算起。
        // 那么为什么[i，j] 区间和为负数，已经起始位置就可以是j+1呢，j+1后面就不会出现更大的负数？
        // 可以这么理解 j之前出现了多少负数，j后面就会出现多少正数，
        // 因为剩余总和是大于零的（前提我们已经确定了一定可以跑完全程）

        int curSum = 0, total = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            curSum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (curSum < 0) {
                curSum = 0;
                start = i + 1;
            }
        }
        if (total < 0) return -1;
        return start;
    }
};

int main() {
    auto func = [](const vector<int>& gas, const vector<int>& cost) {
        Solution s;
        cout << s.canCompleteCircuit(gas, cost) << endl;
    };
    func({1,2,3,4,5}, {3,4,5,1,2});
    func({2,3,4}, {3,4,3});
    return 0;
}

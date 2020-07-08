/*!
 * @brief 跳水板
 *
 * 你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。
 * 返回的长度需要从小到大排列。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if (k == 0) return res; // 特殊情况1：k==0
        res.push_back(shorter * k);
        if (shorter == longer) return res; // 特殊情况2：shorter==longer
        for (int i = 0; i < k; i++) { //dp
            res.push_back(res.back() - shorter + longer); // 正常情况：从0个longer、k个shorter开始，逐次增加longer个数、减小shorter个数，得到的结果自然是递增的，时间线性
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> res = s.divingBoard(1, 2, 3);
    for (int n : res) std::cout << n << std::endl;
    return 0;
}

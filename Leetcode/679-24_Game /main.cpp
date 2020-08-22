/*!
 * @brief 24点游戏
 *
 * 你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。
 *
 * 除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
 * 每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。
 * 例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
 * 你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // 第一步是挑出两个数，算出一个数，取代挑出的两个数，现在有三个数。
    // 在三个数中玩 24 点，再挑出两个数，算出一个数，取代它们，现在有两个数。
    // 在两个数中玩 24 点……
    // 这就有了递归的思路。（回溯）
    // 挑出不同的两数组合，需要两层循环，并且两数不能是同一个数。
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> newNums; // 先转成double，需要计算小数
        for (int num : nums) {
            newNums.emplace_back(static_cast<double>(num));
        }
        return judge(newNums);
    }

    bool judge (vector<double>& nums) {
        if (nums.size() == 1) { // 数组剩一个数的时候，就需要看是不是24了，前面是double型的小数计算，设置一个阈值判断真实值是否为24
            return abs(nums[0] - 24) < 0.00001;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                double n1 = nums[i], n2 = nums[j]; // 取出其中两个数
                vector<double> tmp = nums; // 拷贝一份原数组
                tmp.erase(tmp.begin() + j); // 先删除后面的，这样才对前面的索引没影响
                tmp.erase(tmp.begin() + i);

                // 回溯
                if (insertAndDelAndJudge(tmp, n1 + n2) ||
                insertAndDelAndJudge(tmp, n1 - n2) ||
                insertAndDelAndJudge(tmp, n2 - n1) ||
                insertAndDelAndJudge(tmp, n1 * n2) ||
                (n2 ? insertAndDelAndJudge(tmp, n1 / n2) : 0) ||
                (n1 ? insertAndDelAndJudge(tmp, n2 / n1) : 0)) return true;

                tmp.insert(tmp.begin() + i, n1); // 把前面删去的添加回来，以供下次循环调用
                tmp.insert(tmp.begin() + j, n2); // 先插入靠前的数字，后面的数字的索引才对应到原来的位置
            }
        }
        return false;
    }

    inline bool insertAndDelAndJudge (vector<double>& nums, double t) {
        nums.emplace_back(t); // 用一个新数代替前面被删掉的两个数
        bool res = judge(nums);
        nums.pop_back(); // 需要删去
        return res;
    }
};

int main() {
    vector<int> nums1{4, 1, 8, 7};
    vector<int> nums2{1, 2, 1, 2};
    Solution s;

    std::cout << s.judgePoint24(nums1) << std::endl;
    std::cout << s.judgePoint24(nums2) << std::endl;
    return 0;
}

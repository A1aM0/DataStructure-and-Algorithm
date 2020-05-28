/*!
 * @brief 和为s的连续正数序列
 *
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 *
 * @warning 1 <= target <= 10^5
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static vector<vector<int>> findContinuousSequence(int target) { // 注意“连续”
        // 1. 当窗口的和小于 target 的时候，窗口的和需要增加，所以要扩大窗口，窗口的右边界向右移动
        // 2. 当窗口的和大于 target 的时候，窗口的和需要减少，所以要缩小窗口，窗口的左边界向右移动
        // 3. 当窗口的和恰好等于 target 的时候，我们需要记录此时的结果。也是唯一一个i开头的序列，接下来需要找i+1开头的序列，所以窗口的左边界要向右移动
        int left = 1, right = 2;
        int sum;
        vector<vector<int>> res;
        vector<int> tmp;
        for (left, right; left < right;) {
            sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                tmp.clear();
                for (int i = left; i <= right; ++i) tmp.push_back(i);
                left++;
                right = left + 1;
                res.push_back(tmp);
            }
            else if (sum < target) right++;
            else if (sum > target) left++;
        }
        return res;
    }
};
int main() {
    vector<vector<int>> res = Solution::findContinuousSequence(9);
    for (int i = 0; i < res.size(); ++i) { // print out the result
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

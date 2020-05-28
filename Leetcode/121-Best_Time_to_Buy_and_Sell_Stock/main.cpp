/*!
 * @brief 买卖股票的最佳时机
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 注意你不能在买入股票前卖出股票。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;

        /// @brief 暴力法
        /// @details 思路很简单，计算出每一天个另一天的差值找最大就行
//        for (int i = 0; i < prices.size(); ++i) {
//            for (int j = i + 1; j < prices.size(); ++j){
//                profit = max(profit, prices[j] - prices[i]);
//            }
//        }

        /// @details
        /// 找到历史低位，再用历史低位后面的天数的价格减去最便宜的价格
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // output is 5, 在第二天买入，第五天卖出
//    vector<int> prices = {7, 6, 4, 3, 1}; // output is 0, 没有交易
    std::cout << "max profit is: " << Solution::maxProfit(prices) << std::endl;
    return 0;
}

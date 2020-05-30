/*!
 * @brief 柱状图中最大的矩形
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 */

#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::vector<int> increase; // 单调递增栈，记录的是heights的下标
        heights.push_back(0); // 补一个高为0的条
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!increase.empty() && heights[i] < heights[increase.back()]) { //当前元素比栈顶的小，需要先出栈
                int pos = increase.back();
                increase.pop_back(); // 找到当前元素左侧的较小元素
                // 计算前栈顶元素
                maxArea = std::max(maxArea, heights[pos] * (increase.empty() ? i : (i - increase.back() - 1)));
            }
            increase.push_back(i);
        }
        return maxArea;
    }
};

int main() {
    std::vector<int> nums{1};
    Solution s;
    std::cout << s.largestRectangleArea(nums) << std::endl;
    return 0;
}

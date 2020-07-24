/*!
 * @brief 颜色分类
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 *
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 *
 * 进阶：
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 一次遍历，遇到0和头指针交换，遇到2和尾指针交换，1自然就在中间
        int left = 0, right = nums.size() - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) swap(nums[i], nums[left++]);
            else if (nums[i] == 2) swap(nums[i--], nums[right--]); // 此时i留在原地，因为交换过来的元素不一定是1
        }
    }
};

int main() {
    vector<int> color{2,0,2,1,1,0};
    Solution s;
    s.sortColors(color);
    for (int num : color) {
        std::cout << num << " ";
    }
    cout << std::endl;
    return 0;
}

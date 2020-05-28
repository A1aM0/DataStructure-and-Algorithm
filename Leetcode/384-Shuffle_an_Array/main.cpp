/*!
 * @brief 打乱数组
 *
 * 打乱一个没有重复元素的数组。
 */

#include <iostream>
#include <vector>

class Solution { // https://labuladong.gitbook.io/algo/suan-fa-si-wei-xi-lie/xi-pai-suan-fa
public:
    Solution(std::vector<int>& nums) {
        array = nums;
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return array;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() {
        std::vector<int> tmp(array);
        for (int i = 0; i < tmp.size(); ++i) {
            int r = rand() % (tmp.size() - i) + i;
            std::swap(tmp[i],tmp[r]);
        }
        return tmp;
    }

private:
    std::vector<int> array;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

int main() {
    std::vector<int> nums = {1,2,3};
    Solution *obj = new Solution(nums);
    std::vector<int> param_1 = obj->reset();
    std::vector<int> param_2 = obj->shuffle();

    for (auto num : param_1) std::cout << num << " ";
    std::cout << std::endl;
    for (auto num : param_2) std::cout << num << " ";
    return 0;
}

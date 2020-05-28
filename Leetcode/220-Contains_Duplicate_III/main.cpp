/*!
 * @brief 存在重复元素 III
 *
 * 给定一个整数数组，判断数组中是否有两个不同的索引 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。
 */

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        // 判断是否存在 |nums[i] - nums[j]| <= t && |i - j| <= k。
        // 所以前式可变换得到 nums[?] >= nums[i] - t 且该数nums[?]还满足 nums[?] <= nums[i] + t。
        // 先根据前面的不等式找到nums[?]。在拿找打的带入到后面的不等式里看是否成立。
        // 若成立，则true；反之，需要继续找。
        // 怎么找nums[?]：
        // 因为限制了|i - j|的最大值，所以可以用一个容器，里面最多依次放nums数组里的k个元素，在这个容器里找一个大于 nums[i] - t 的元素；
        // 可以记为s，若这个s满足了另一个不等式，自然返回true；
        // 若不满足。说明在当前k个元素里，没有合适的，需要进行下一轮判断；
        // 注意当前容器里k个元素角标的范围最大是[i-k, i)，所以进行下一轮之前，判断如果给容器里新加入了一个数nums[i]的话，将再从容器里删去nums[i-k]。
        // 选择[i-k, i)的原因是：如果在某个区间找到存在题目条件的数，最极端的情况将是 i 与 i+1 ，当找到时，容器的范围是 [i-k, i-1] 或者说 [i-k,i) ，
        // 将插入且还未插入nums[i]，可以找满足不等式条件的时候，排除它自身。
        set<double> bst;
        for (int i = 0; i < nums.size(); ++i) {
            auto s = bst.lower_bound((double)nums[i] - (double)t);
            if (s != bst.end() && *s <= (double)nums[i] + (double)t) return true;
            bst.insert(nums[i]);
            if (bst.size() > k) bst.erase(nums[i - k]);
        }
        return false;
    }
};

int main() {
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3, t1 = 0;
    vector<int> nums2 = {1,0,1,1};
    int k2 = 1, t2 = 2;
    vector<int> nums3 = {1,5,9,1,5,9};
    int k3 = 2, t3 = 3;

    Solution s;

    std::cout << "result is " << (s.containsNearbyAlmostDuplicate(nums1, k1, t1) ? "true" : "false") << std::endl;
    return 0;
}

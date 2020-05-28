/*!
 * @brief 将有序数组转换为二叉搜索树
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 */

#include <iostream>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 划分到简单题的原因就是已经给定数组了，甚至是有序的。
        // 可以直接从数组的中位数做根结点，挨个往下添，这里流程和二分特别像了。
        // 如果随机给数字，给一个插入一个结点的话，存在子树旋转的问题，难度提升了。
        return convert2Tree(nums, 0, nums.size() - 1);
    }
    TreeNode* convert2Tree (vector<int> &nums, int start, int end) {
        int l = start, r = end;
        if (r < l) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = convert2Tree(nums, l, mid - 1);
        node->right = convert2Tree(nums, mid + 1, r);
        return node;
    }
};

int main() {
    vector<int> nums = {-10,-3,0,5,9};
    Solution s;
    s.sortedArrayToBST(nums);

    // no test instance
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

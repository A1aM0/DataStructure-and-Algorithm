/*!
 * @brief 二叉搜索树中第K小的元素
 *
 * 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 *
 * 说明：
 * 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 */

#include <iostream>
#include <stack>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
    vector<int> nums;
public:
    int kthSmallest(TreeNode* root, int k) { // 中序遍历，递归
        dfs(root);
        return nums[k - 1];
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }

public:
    int kthSmallest_die_dai(TreeNode* root, int k) { // 中序遍历，迭代
        stack<TreeNode*> stack;
        TreeNode* cur = root;

        while (cur || !stack.empty()) {
            if (cur) {
                stack.push(cur);
                cur = cur->left;
            } else {
                cur = stack.top();
                stack.pop();
                if (--k == 0) return cur->val;
                cur = cur->right;
            }
        }
        return 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

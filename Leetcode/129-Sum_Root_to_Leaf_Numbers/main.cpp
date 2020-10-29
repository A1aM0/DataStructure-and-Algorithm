/*!
 * @brief 求根到叶子节点数字之和
 *
 * 给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。
 * 例如，从根到叶子节点路径 1->2->3 代表数字 123。
 * 计算从根到叶子节点生成的所有数字之和。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 */

#include <iostream>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        // 根节点开始，遍历每个节点，
        // 如果遇到叶子节点，则将叶子节点对应的数字加到数字之和。
        // 如果当前节点不是叶子节点，则计算其子节点对应的数字，
        // 然后对子节点递归遍历。
        return dfs(root, 0);
    }

    int dfs (TreeNode* root, int tmp) {
        if (!root) {
            return 0;
        }
        int sum = tmp * 10 + root->val;
        if (!root->left && !root->right) {
            return sum;
        } else {
            int left = dfs(root->left, sum);
            int right = dfs(root->right, sum);
            return left + right;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

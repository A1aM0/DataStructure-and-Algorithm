/*!
 * @brief 平衡二叉树
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 本题中，一棵高度平衡二叉树定义为：
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        if (abs(calHeight(root->left) - calHeight(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int calHeight(TreeNode *root) { // 递归的计算当前结点的高度
        if (!root) return 0;
        int leftHeight = calHeight(root->left) + 1;
        int rightHeight = calHeight(root->right) + 1;
        return leftHeight > rightHeight ? leftHeight : rightHeight;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

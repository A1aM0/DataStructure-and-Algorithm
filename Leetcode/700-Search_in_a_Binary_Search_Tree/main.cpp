/*!
 * @brief 二叉搜索树中的搜索
 *
 * 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。
 * 如果节点不存在，则返回 NULL。
 */

#include <iostream>
#include "../dataStructure.hxx"

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->val == val) return root;
    else if (root->val > val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

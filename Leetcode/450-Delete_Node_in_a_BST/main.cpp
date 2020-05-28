/*!
 * @brief  删除二叉搜索树中的节点
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 一般来说，删除节点可分为两个步骤：
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 *
 * 说明：
 * 要求算法时间复杂度为 O(h)，h 为树的高度。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val == key) {
            // 找到该结点后分三种可能性：1. 结点为叶子结点；2. 结点有且仅有一个子树；3. 结点有两个孩子
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                // 有两个孩子
                TreeNode *tmp = root->left;
                while (tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = root->right;
                return root->left;
            }
        } else if (root->val > key) root->left = deleteNode(root->left, key); // 递归的找左子树
        else root->right = deleteNode(root->right, key);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

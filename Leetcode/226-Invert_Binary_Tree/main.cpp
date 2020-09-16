/*!
 * @brief 翻转二叉树
 *
 * 翻转一棵二叉树。
 */

#include <iostream>
#include "../dataStructure.hxx"
#include <stack>

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* l = invertTree(root->left);
        TreeNode* r = invertTree(root->right);

        root->left = r;
        root->right = l;
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

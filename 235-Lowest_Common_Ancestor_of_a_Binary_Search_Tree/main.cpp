/*!
 * @brief 二叉搜索树的最近公共祖先
 *
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 二叉搜索树的性质，凡是公共祖先必小于一个且大于另一个，递归就完了
        if (!root) return NULL;
        if ((root->val - p->val) * (root->val - q->val) <= 0) return root;
        else if (root->val > q->val && root->val > p->val) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

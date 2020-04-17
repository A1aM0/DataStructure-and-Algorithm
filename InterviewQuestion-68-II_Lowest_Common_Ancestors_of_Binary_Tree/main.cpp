/*!
 * @brief 二叉树的最近公共祖先
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 *
 * 说明:
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 */
#include <iostream>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 边界条件讨论：
        // 如果root是null，则说明我们已经找到最底了，返回null表示没找到
        // 如果root与p相等或者与q相等，则返回root
        // 如果左子树没找到，递归函数返回null，证明p和q同在root的右侧，那么最终的公共祖先就是右子树找到的结点
        // 如果右子树没找到，递归函数返回null，证明p和q同在root的左侧，那么最终的公共祖先就是左子树找到的结

        //先找到p或者q就返回
        if(root == NULL || root == p || root == q) return root;
        //在左子树找p或q，假如p和q都在左子树，返回的那个值就是祖先
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        //在右子树找p或者q，假如p和q都在右子树，返回的那个值就是祖先
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if(left == NULL) return right;
        if(right == NULL) return left;
        // p和q一个在左子树一个在右子树
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

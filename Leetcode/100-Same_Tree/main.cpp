/*!
 * @brief 相同的树
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); // 用p和q的val比较，毕竟实际上是两棵树，要是直接比较pq那必不相等。
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

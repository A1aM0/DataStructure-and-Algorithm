/*!
 * @brief 另一个树的子树
 *
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        // 和100题有点像，那么可以仿照思路。
        // 要是先序遍历再加KMP的话，太复杂了也不符合“简单题”的分类哈哈哈。
        // 按照题目，子树指t必须从开始相等节点开始，直到全部的叶子节点都相等才满足条件。
        if (!t) return true;
        if (!s) return false;

        // 对s的每一个结点及其子树们都做一次sameTree，用或连起来就行，凡是存在子树的话，结果为1。（dfs遍历每一个结点）
        return isSubtree(s->left, t) || isSubtree(s->right, t) || sameTree(s, t);
    }

    bool sameTree (TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if (!s || !t) return false;
        return s->val == t->val && sameTree(s->left, t->left) && sameTree(s->right, t->right);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

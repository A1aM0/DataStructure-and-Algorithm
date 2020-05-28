/*!
 * @brief 二叉搜索树迭代器
 *
 * 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
 * 调用 next() 将返回二叉搜索树中的下一个最小的数。
 */

#include <iostream>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class BSTIterator {
    // 把中序遍历拆开到两个函数里，算法的核心依旧是中序遍历
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            tree.push_back(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *min = tree.back();
        tree.pop_back();

        TreeNode *tmp = min->right;
        while (tmp) {
            tree.push_back(tmp);
            tmp = tmp->left;
        }

        return min->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !tree.empty();
    }

private:
    vector<TreeNode*> tree;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

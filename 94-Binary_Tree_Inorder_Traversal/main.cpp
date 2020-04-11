/*!
 * @brief 二叉树的中序遍历
 *
 * 给定一个二叉树，返回它的 中序 遍历。
 */

#include <iostream>
#include <vector>
#include <stack>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // 递归
//        recursive(root);
        // 迭代
        iterate(root);
        return res;
    }

private:
    void recursive(TreeNode* node) {
        if (!node) return;
        recursive(node->left);
        res.push_back(node->val);
        recursive(node->right);
    }
    void iterate (TreeNode* node) {
        // 迭代
        // 递归对系统而言是使用栈，所以迭代的时候也用栈模拟递归，注意压栈的顺序
        if (!node) return;

        // 先压最左子树
        stack<TreeNode*> stk;
        while (node) {
            stk.push(node);
            node = node->left;
        }

        // pop最左叶子结点之后，访问其右子，再找右子的最左结点
        while (!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            tmp = tmp->right;
            while (tmp) {
                stk.push(tmp);
                tmp = tmp->left;
            }
        }
    }
    vector<int> res;
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    node1->right = node2;
    node2->left = node3;
    Solution s;
    vector<int> res = s.preorderTraversal(node1);
    for (int nodeVal : res) cout << nodeVal << " ";
    return 0;
}

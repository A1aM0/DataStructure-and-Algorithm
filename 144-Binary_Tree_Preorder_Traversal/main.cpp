/*!
 * @brief 二叉树的前序遍历
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
        res.push_back(node->val);
        recursive(node->left);
        recursive(node->right);
    }
    void iterate (TreeNode* node) {
        // 迭代
        // 递归对系统而言是使用栈，所以迭代的时候也用栈模拟递归，注意栈的顺序，先压右子树
        if (!node) return;

        stack<TreeNode*> stk;
        stk.push(node);
        while (!stk.empty()) {
            TreeNode* tmp = stk.top();
            res.push_back(tmp->val);
            stk.pop();
            if (tmp->right) stk.push(tmp->right);
            if (tmp->left) stk.push(tmp->left);
        }
        return;
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

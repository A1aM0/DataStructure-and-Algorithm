/*!
 * @brief 二叉树的后序遍历
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 */

#include <iostream>
#include <vector>
#include <stack>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
        recursive(node->right);
        res.push_back(node->val);
    }
    void iterate (TreeNode* node) {
        // 迭代
        // 递归对系统而言是使用栈，所以迭代的时候也用栈模拟递归，注意压栈的顺序
        // 自己画个图很好懂
        if (!node) return;

        stack<TreeNode*> stk;
        stk.push(node);

        while (!stk.empty()) {
            auto stkTop = stk.top();
            if (stkTop->right) stk.push(stkTop->right);
            if (stkTop->left) stk.push(stkTop->left);
            if(!stkTop->left && !stkTop->right) {
                res.push_back(stkTop->val);
                stk.pop();
            }
            stkTop->left = stkTop->right = nullptr;
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
    vector<int> res = s.postorderTraversal(node1);
    for (int nodeVal : res) cout << nodeVal << " ";
    return 0;
}

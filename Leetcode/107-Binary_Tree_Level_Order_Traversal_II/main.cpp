/*!
 * @brief 二叉树的层次遍历 II
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 */

#include <iostream>
#include "../dataStructure.hxx"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        //在遍历完一层节点之后，将存储该层节点值的列表添加到结果列表的头部。
        // 和正常的层序遍历相反即可，用栈代替队列也可；或者使用vector，最后reverse
        if (!root) return {};
        stack<vector<TreeNode*>> sk;
        vector<TreeNode*> tmp;
        tmp.emplace_back(root);
        sk.push(tmp);
        while (!tmp.empty()) {
            tmp.clear();
            int size = sk.top().size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = sk.top()[i];
                if (node->left) tmp.emplace_back(node->left);
                if (node->right) tmp.emplace_back(node->right);
            }
            if (tmp.empty()) continue;
            sk.push(tmp);
        }
        vector<vector<int>> res;
        while (!sk.empty()) {
            vector<int> r;
            for (int i = 0; i < sk.top().size(); i++) {
                r.emplace_back(sk.top()[i]->val);
            }
            res.emplace_back(r);
            sk.pop();
        }
        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

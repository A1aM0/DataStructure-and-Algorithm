/*!
 *@brief 二叉树的右视图
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 * @exmple
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 */

#include <iostream>
#include <vector>
#include <queue>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if (!root) return view;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            view.push_back(q.back()->val);
            while (size--) {
                TreeNode* tmp = q.front();
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
        }
        return view;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

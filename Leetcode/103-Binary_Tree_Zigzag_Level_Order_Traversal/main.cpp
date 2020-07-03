/*!
 * @brief 二叉树的锯齿形层次遍历
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 */

#include <iostream>
#include <vector>
#include <deque>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        bool zigzag = true;
        deque<TreeNode*> nodeList;
        nodeList.push_back(root);
        while (!nodeList.empty()) {
            int size = nodeList.size();
            vector<int> tmp;
            TreeNode* node;
            while (size) {
                if (zigzag) {
                    node = nodeList.front();
                    nodeList.pop_front();
                    if (node->left) nodeList.push_back(node->left);
                    if (node->right) nodeList.push_back(node->right);
                } else {
                    node = nodeList.back();
                    nodeList.pop_back();
                    if (node->right) nodeList.push_front(node->right);
                    if (node->left) nodeList.push_front(node->left);
                }
                tmp.push_back(node->val);
                size--;
            }
            zigzag = !zigzag;
            res.push_back(tmp);
        }

        return res;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

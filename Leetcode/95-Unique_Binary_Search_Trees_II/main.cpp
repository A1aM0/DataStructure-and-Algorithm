/*!
 * @brief 不同的二叉搜索树 II
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
 */

#include <iostream>
#include <vector>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) { // dfs
        if (start > end) return {NULL};
        vector<TreeNode*> arr;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftChild = generateTrees(start, i - 1);
            vector<TreeNode*> rightChild = generateTrees(i + 1, end);
            for (TreeNode* left : leftChild) {
                for (TreeNode* right : rightChild) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    arr.emplace_back(root);
                }
            }
        }
        return arr;
    }
};

int main() {
    Solution s;
    s.generateTrees(3);
    return 0;
}

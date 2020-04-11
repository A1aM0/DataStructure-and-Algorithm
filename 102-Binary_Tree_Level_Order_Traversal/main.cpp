/*!
 * @brief 二叉树的层序遍历
 *
 * 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
 */

#include <iostream>
#include <vector>
#include <queue>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> tmp;
            int layerLength = q.size(); // 操作到某一层时，队列中只有该层的元素，即可得该层结点数量
            while (layerLength--) {
                // 每层的操作，layerLength减完了则这一层遍历完了，队列中新的结点是下一层的
                auto qHead = q.front();
                tmp.push_back(qHead->val);
                q.pop();
                if(qHead->left) q.push(qHead->left);
                if(qHead->right) q.push(qHead->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {
    //3,9,20,null,null,15,7
    TreeNode *node1 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node3 = new TreeNode(20);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    Solution s;
    vector<vector<int>> res = s.levelOrder(node1);
    for (vector<int> layer : res) {
        for (int nodeVal : layer) cout << nodeVal << " ";
        cout << endl;
    }
    return 0;
}


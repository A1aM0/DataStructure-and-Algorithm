/*!
 * @brief 填充每个节点的下一个右侧节点指针 II
 *
 * 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
 * 初始状态下，所有 next 指针都被设置为 NULL。
 *
 * 进阶：
 * 你只能使用常量级额外空间。
 * 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
 */
#include <iostream>

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }
    void dfs(Node* root) {
        // 依旧是为自己的两个孩子分配next。
        // 1. 若两个孩子都存在，左孩子的next即为右孩子；
        // 2. 若只有一个孩子（以及若两个孩子都有，右孩子）的next，则为本结点的next的孩子结点：
        // 2.1 若本结点next结点有左孩子，则为左；
        // 2.2 若本结点next结点只有右孩子，则为右。

        // ③ 判断是不是空树，或者递归到了叶子节点，直接返回
        if (!root || (!root->left && !root->right)) return;

        // ①
        if (root->left && root->right) root->left->next = root->right;

        // ②
        Node* only_OR_rightChild = root->right ? root->right : root->left;
        Node* rootNext = root->next;
        while (rootNext) {
            if (rootNext->left) {
                only_OR_rightChild->next = rootNext->left;
                break;
            }
            else if (rootNext->right) {
                only_OR_rightChild->next = rootNext->right;
                break;
            }
            // 一直找到root右边有孩子的结点
            rootNext = rootNext->next;
        }

        // 根据前面的思路，先把右边找完，在找左边的
        dfs(root->right);
        dfs(root->left);
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

/*!
 * @brief 二叉树的序列化与反序列化
 *
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，
 * 同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 *
 * 请设计一个算法来实现二叉树的序列化与反序列化。
 * 这里不限定你的序列 / 反序列化算法执行逻辑，
 * 你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 *
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
 */

#include <iostream>
#include <queue>
#include "../dataStructure.hxx"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { // dfs先序
        if (!root) return "#,";

        string str = to_string(root->val) + ",";
        str += serialize(root->left);
        str += serialize(root->right);

        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { // 需要把string里的每一个数字组合成原本的数，并抛弃逗号
        queue<string> nodes;
        string tmp;
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == ',') {
                nodes.push(tmp);
                tmp.clear();
            } else {
                tmp += data[i];
            }
        }
        return deserialize(nodes);
    }

    TreeNode* deserialize(queue<string> &nodes) {
        string front = nodes.front();
        nodes.pop();

        if (front == "#") {
            return NULL;
        }

        TreeNode* newNode = new TreeNode(stoi(front));
        newNode->left = deserialize(nodes);
        newNode->right = deserialize(nodes);
        return newNode;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

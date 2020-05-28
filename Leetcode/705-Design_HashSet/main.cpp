/*!
 * @brief 设计哈希集合
 *
 * 不使用任何内建的哈希表库设计一个哈希集合
 * 具体地说，你的设计应该包含以下的功能
 * add(value)：向哈希集合中插入一个值。
 * contains(value) ：返回哈希集合中是否存在这个值。
 * remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 *
 * 注意：
 * 所有的值都在 [0, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希集合库。
 */

#include <iostream>
#include "../dataStructure.hxx"
#include <vector>
using namespace std;

class MyHashSet {
public:
    MyHashSet() {
        set = vector<ListNode*>(len, new ListNode(-1));
    }

    void add(int key) {
        int hashVal = key % len;
        ListNode *node = set[hashVal];
        if (node->val != -1) {
            while (node) {
                if (node->val == key) return;
                if (!node->next) node->next = new ListNode(key);
                else node = node->next;
            }
        } else {
            node->val = key;
        }
    }

    void remove(int key) {
        int hashVal = key % len;
        ListNode *node = set[hashVal];
        if (node->val != -1) {
            while (node) {
                if (node->val == key) node->val = -1;
                else node = node->next;
            }
        }
    }

    bool contains(int key) {
        int hashVal = key % len;
        ListNode *node = set[hashVal];
        while (node) {
            if (node->val == key) return true;
            else node = node->next;
        }
        return false;
    }

private:
    vector<ListNode*> set;
    const int len = 199;
};

int main() {
    MyHashSet hashSet;
    hashSet.add(1);
    hashSet.add(2);
    hashSet.contains(1);    // 返回 true
    hashSet.contains(3);    // 返回 false (未找到)
    hashSet.add(2);
    hashSet.contains(2);    // 返回 true
    hashSet.remove(2);
    hashSet.contains(2);    // 返回  false (已经被删除)
    return 0;
}

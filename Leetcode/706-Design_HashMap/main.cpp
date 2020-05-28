/*!
 * @brief 设计哈希映射
 *
 * 不使用任何内建的哈希表库设计一个哈希映射
 * 具体地说，你的设计应该包含以下的功能
 * put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
 * get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
 * remove(key)：如果映射中存在这个键，删除这个数值对。
 */

#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map = vector<ListNode*>(len, new ListNode(-1, -1));
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashVal = key % len;
        ListNode *node = map[hashVal];
        ListNode *pre;

        while (node) {
            if (node->key == key) {
                node->val = value;
                return;
            }
            pre = node;
            node = node->next;

        }
        ListNode *newNode = new ListNode(key, value);
        pre->next = newNode;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashVal = key % len;
        ListNode *node = map[hashVal];
        while (node) {
            if (node->key == key) return node->val;
            node = node->next;
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashVal = key % len;
        ListNode *node = map[hashVal];
        while (node) {
            if (node->key == key) node->val = -1; // 直接更新成-1，也满足了再找当前key的话找不到就返回-1的设定
            node = node->next;
        }
    }

private:
    struct ListNode {
        int key;
        int val;
        ListNode *next;
        ListNode(int key, int val) : key(key), val(val), next(NULL) {}
    };
    vector<ListNode*> map;
    const int len = 199;
};

int main() {
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    hashMap.get(1);            // 返回 1
    hashMap.get(3);            // 返回 -1 (未找到)
    hashMap.put(2, 1);         // 更新已有的值
    hashMap.get(2);            // 返回 1
    hashMap.remove(2);         // 删除键为2的数据
    hashMap.get(2);            // 返回 -1 (未找到)
    return 0;
}

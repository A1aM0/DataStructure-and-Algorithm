/*!
 * @brief LRU缓存机制
 *
 * 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
 * 获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
 * 写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
 *
 * 进阶:
 * 你是否可以在 O(1) 时间复杂度内完成这两种操作？
 */

#include <iostream>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        head = new doubleLinkNode();
        tail = new doubleLinkNode();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        doubleLinkNode *tmp = cache[key];
        move2tail(tmp);
        return tmp->val;
    }

    void put(int key, int value) {
        if (cache.count(key)) { // 缓存中存在
            doubleLinkNode *tmp = cache[key];
            tmp->val = value;
            move2tail(tmp);
        } else { // 缓存中不存在，需要新入队，所以分队满和不满两种情况
            doubleLinkNode *tmp = new doubleLinkNode(key, value);
            cache[key] = tmp;
            size++;
            addTail(tmp);
            if (size > capacity) {
                removeEarliest();
                --size;
            }
        }
    }

private:
    struct doubleLinkNode {
        int key, val;
        doubleLinkNode* pre;
        doubleLinkNode* next;
        doubleLinkNode(int k = 0, int v = 0) : key(k), val(v), pre(NULL), next(NULL) {}
    }; // 双向链表的队列，最早的页面在head->next
    std::unordered_map<int, doubleLinkNode*> cache; // key = LRUkey, val = key-val-Node
    int size, capacity;
    doubleLinkNode *head, *tail;

    void remove(doubleLinkNode *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    void move2tail (doubleLinkNode *node) {
        remove(node);
        addTail(node);
    }

    void addTail (doubleLinkNode *node) { // 将结点添加到队列
        node->pre = tail->pre;
        node->next = tail;
        tail->pre->next = node;
        tail->pre = node;
    }

    void removeEarliest () {
        doubleLinkNode *del = head->next;
        remove(del);
        cache.erase(del->key);
        delete del;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << cache.get(1);       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    std::cout << cache.get(2);       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    std::cout << cache.get(1);       // 返回 -1 (未找到)
    std::cout << cache.get(3);       // 返回  3
    std::cout << cache.get(4);       // 返回  4
    return 0;
}

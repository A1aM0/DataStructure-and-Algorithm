/*!
 * @brief 设计链表
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。
 * val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。
 * 假设链表中的所有节点都是 0-index 的。
 *
 * 在链表类中实现这些功能：
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 *
 * @warning
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 */

#include <iostream>

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList():head(nullptr) {}

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        singleLinkListNode* p;
        p = head;
        while (p && i < index) {
            p = p->next;
            ++i;
        }
        if (p) return p->val;
        else return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        singleLinkListNode* node = new singleLinkListNode(val); ///< 新建一个节点，然后让这个节点变为head
        node->next = head;
        head = node;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        singleLinkListNode* node = new singleLinkListNode(val); ///< 新建结点，注意需要让链表原先尾结点指向这个新的

        if (head == nullptr) { // 如果链表是空的，则这个尾结点就是头结点
            head = node;
            return;
        }

        singleLinkListNode* p = head;
        while (p->next) p = p->next; ///< 遍历q的next域信息，直到原链表的最后一个结点
        p->next = node;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        singleLinkListNode* node = new singleLinkListNode(val);
        if (index < 1) { // 考虑index小于等于0，则直接插入到链表的开始位置
            node->next = head;
            head = node;
            return;
        }

        singleLinkListNode* p = head;
        int i = 0;
        while (i < index - 1  && p) { // 遍历到目标位置的前驱
            ++i;
            p = p->next;
        }
        if (p) { // 此时p是前驱
            node->next = p->next;
            p->next = node;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index == 0 && head != nullptr) { // 要删头结点的话，直接删掉，第二个结点变为头结点
            singleLinkListNode* del = head;
            head = head->next;
            delete del;
            return;
        }

        singleLinkListNode* p = head;
        int i = 0;
        while (i < index - 1 && p) { // 遍历到要删除的位置的前驱
            p = p->next;
            ++i;
        }
        if (!p) return; // 如果index超出了链表长度，则不删除任何结点
        if (p->next) {
            singleLinkListNode* del = p->next;
            p->next = del->next;
            delete del;
        }
    }

private:
    struct singleLinkListNode{
        int val;
        singleLinkListNode* next;
        singleLinkListNode(int x): val(x), next(nullptr) {}
    };
    singleLinkListNode* head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);
    linkedList.get(1);
    linkedList.deleteAtIndex(0);
    linkedList.get(0);
//    linkedList.addAtIndex(0, 10);
//    linkedList.addAtIndex(0, 20);
//    linkedList.addAtIndex(1, 30);
//    linkedList.deleteAtIndex(0);
    for (int i = 0; i < 3; ++i) std::cout << linkedList.get(i) << " ";
    return 0;
}

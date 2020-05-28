/*!
 * @brief 删除链表的倒数第N个节点
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 * 说明：给定的 n 保证是有效的。
 * 进阶：你能尝试使用一趟扫描实现吗？
 */

#include <iostream>

class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x): val(x), next(nullptr) {}
    };

    static ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* headFront = new ListNode(0);
        headFront->next = head;
        ListNode* p = headFront;
        ListNode* q = headFront;
        for (int i = 0; i < n; ++i) q = q->next;

        while (q && q->next) {
            p = p->next;
            q = q->next;
        }

        ListNode* del = p->next;
        p->next = del->next;
        delete del;

        ListNode* tmp = headFront->next;
        delete headFront;
        return tmp;
    }
};

void printList (Solution::ListNode *head) {
    Solution::ListNode* p = head;
    while (p) {
        std::cout << p->val << std::endl;
        p = p->next;
    }
}
int main() {
    Solution::ListNode* node1 = new Solution::ListNode(1);
    Solution::ListNode* node2 = new Solution::ListNode(2);
    Solution::ListNode* node3 = new Solution::ListNode(3);
    Solution::ListNode* node4 = new Solution::ListNode(4);
    Solution::ListNode* node5 = new Solution::ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    printList(node1);

    node1 = Solution::removeNthFromEnd(node1, 2);
    printList(node1);
    return 0;
}

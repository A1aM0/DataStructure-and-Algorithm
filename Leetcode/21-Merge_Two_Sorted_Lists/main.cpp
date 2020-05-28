/*!
 * @brief 合并两个有序的链表
 *
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 *
 * @example
 * 示例：
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;

        // 找一个虚拟头结点（官方叫“哨兵节点”），然后依次比l1和l2的大小，将哨兵的next指向小的那个，最后返回哨兵的头部
        ListNode *p = l1, *q = l2, *tmp;
        ListNode *head = new ListNode(-1);
        tmp = head;
        while (p && q) {
            if (p->val < q->val) {
                tmp->next = p;
                p = p->next;
            } else {
                tmp->next = q;
                q = q->next;
            }
            tmp = tmp->next;
        }
        tmp->next = (p) ? p : q; // 退出循环意味着p或q有一个空了，那么将tmp->next直接接到另一个链表上就完了
        return head->next;
    }
};

int main() {
    ListNode *l1Node1 = new ListNode(1);
    ListNode *l1Node2 = new ListNode(2);
    ListNode *l1Node3 = new ListNode(4);
    l1Node1->next = l1Node2;
    l1Node2->next = l1Node3;

    ListNode *l2Node1 = new ListNode(1);
    ListNode *l2Node2 = new ListNode(3);
    ListNode *l2Node3 = new ListNode(4);
    l2Node1->next = l2Node2;
    l2Node2->next = l2Node3;

    ListNode *resHead = Solution::mergeTwoLists(l1Node1, l2Node1);

    while (resHead) {
        std::cout << resHead->val << std::endl;
        resHead = resHead->next;
    }
    return 0;
}

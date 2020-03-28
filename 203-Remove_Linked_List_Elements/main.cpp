/*!
 * @brief
 * Remove Linked List Elements
 *
 * @details
 * 删除链表中等于给定值 val 的所有节点。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    static ListNode* removeElements(ListNode* head, int val) {
        // 遍历过去
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;

        while (p->next) {
            if (p->next->val == val) {
                ListNode *del = p->next;
                p->next = p->next->next;
                delete del;
            } else {
                p = p->next;
            }
        }

        return dummy->next;
    }
};

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(6);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(4);
    ListNode* node6 = new ListNode(5);
    ListNode* node7 = new ListNode(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;


    node1 = Solution::removeElements(node1, 6);
    while (node1) {
        std::cout << node1->val << std::endl;
        node1 = node1->next;
    }
    return 0;
}

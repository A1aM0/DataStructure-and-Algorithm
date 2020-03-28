/*!
 * @brief 奇偶链表
 *
 * 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
 * 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 *
 * @example
 * 输入: 1->2->3->4->5->NULL
 * 输出: 1->3->5->2->4->NULL
 *
 * 输入: 2->1->3->5->6->4->7->NULL
 * 输出: 2->3->6->7->1->5->4->NULL
 *
 * @note
 * 应当保持奇数节点和偶数节点的相对顺序。
 * 链表的第一个节点视为奇数节点，第二个节点视为偶数节点，以此类推。
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    static ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        //列出两个子链表，最后再接上
        ListNode *odd, *even, *tmp;
        odd = head;
        even = head->next;
        tmp = even;

        while (even && even->next) {
            // odd是一条奇数链表
            odd->next = odd->next->next;
            odd = odd->next;

            // even是一条偶数链表
            even->next = even->next->next;
            even = even->next;
        }
        // 把odd的尾部接到even的头部
        odd->next = tmp;
        return head;
    }
};

int main() {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;

    node1 = Solution::oddEvenList(node1);
    while (node1) {
        std::cout << node1->val << std::endl;
        node1 = node1->next;
    }
    return 0;
}

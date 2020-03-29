/*!
 * @brief 两数相加
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 *
 * @example
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 */

#include <iostream>
#include "../dataStructure.hxx"

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 注意输出同样是逆序即可，第一遍做的时候没注意，以为要正序输出，那么在反转链表的时候假设的head结点也会被输出，就会出现问题
        // 感觉上述问题：可以设置一个计数器，记录结果的位数，再生成新正序链表的时候作为限制，但是这样的话就不能原地反转链表了，需要一个新的链表来存储，反转算法的空间复杂度从O(1)变成O(n)
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            ListNode *newNode = new ListNode(sum % 10);
            p->next = newNode;
            p = p->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return head->next;
    }
};

int main() {
    ListNode *l1Node1 = new ListNode(2);
    ListNode *l1Node2 = new ListNode(4);
    ListNode *l1Node3 = new ListNode(3);
    ListNode *l2Node1 = new ListNode(5);
    ListNode *l2Node2 = new ListNode(6);
    ListNode *l2Node3 = new ListNode(4);
    l1Node1->next = l1Node2;
    l1Node2->next = l1Node3;
    l2Node1->next = l2Node2;
    l2Node2->next = l2Node3;

    ListNode *res = Solution::addTwoNumbers(l1Node1, l2Node1);
    while (res) {
        std::cout << res->val;
        res = res->next;
    }
    return 0;
}

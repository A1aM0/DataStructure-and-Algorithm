/*!
 * @brief 两数相加 II
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 *
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 */

#include <iostream>
#include <stack>
#include "../dataStructure.hxx"
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode *res = nullptr;
        while(!stk1.empty() || !stk2.empty() || carry > 0) {
            int sum = carry;
            if (!stk1.empty()) {
                sum += stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                sum += stk2.top();
                stk2.pop();
            }
            carry = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            node->next = res;
            res = node;
        }
        return res;
    }
};

int main() {
    return 0;
}

/*!
 * @brief 相交链表
 *
 * @details
 * 编写一个程序，找到两个单链表相交的起始节点。
 * 如下面的两个链表：
 * a1 -> a2 -> a3 ->
 *                   c1 -> c2
 * b1-> b2->
 * 在节点 c1 开始相交。
 *
 * @warning
 * 如果两个链表没有交点，返回 null.
 * 在返回结果后，两个链表仍须保持原有的结构。
 * 可假定整个链表结构中没有循环。
 * 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
 */

#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {};
    };

    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        while (ptr1 != ptr2) {
            ptr1 = ptr1 ? ptr1->next : headB;
            ptr2 = ptr2 ? ptr2->next : headA;
            /// 判断条件是ptr而不是ptr->next。
            /// 是因为假如两个链表不相交的话，总有一刻会在尾结点的next处相遇，
            /// 这样两个ptr都为null且相等，也可以返回null。
            /// 反之，要是依据ptr->next判断的话。当ptr1走到尾结点时，需先记录这个尾结点的信息temp，
            /// 等ptr2走到的时候，再和temp比较，若两个尾结点不同，则直接证明了两个链表不相交。
            /// 如果用ptr->next而不比较尾结点的话，则会陷入无限循环（遇到不相交的链表的时候）
        }
        return ptr1;
    }
};
int main() {
    Solution::ListNode* list_a_1 = new Solution::ListNode(4);
    Solution::ListNode* list_a_2 = new Solution::ListNode(1);
    Solution::ListNode* list_a_3 = new Solution::ListNode(8);
    Solution::ListNode* list_a_4 = new Solution::ListNode(4);
    Solution::ListNode* list_a_5 = new Solution::ListNode(5);
    list_a_1->next = list_a_2;
    list_a_2->next = list_a_3;
    list_a_3->next = list_a_4;
    list_a_4->next = list_a_5;

    Solution::ListNode* list_b_1 = new Solution::ListNode(5);
    Solution::ListNode* list_b_2 = new Solution::ListNode(0);
    Solution::ListNode* list_b_3 = new Solution::ListNode(1);

    list_b_1->next = list_b_2;
    list_b_2->next = list_b_3;
    list_b_3->next = list_a_3;


    std::cout << Solution::getIntersectionNode(list_a_1, list_b_1)->val << std::endl; // output is 8

    return 0;
}

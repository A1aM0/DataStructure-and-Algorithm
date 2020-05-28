/*!
 * @brief K 个一组翻转链表
 * 
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 示例：
 * 给你这个链表：1->2->3->4->5
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明：
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy;
        
        // 基本思路是通过k来划分子组，然后依次反转，难点再子组反转后再连接起来
        while (true) {
            int cnt = 0;
            ListNode *tail = pre;

            while (tail && cnt != k) { // 暴力划分子组，这里子组的范围应该是[pre->next, tail]，pre用作标志位
                cnt++;
                tail = tail->next;
            }
            if (!tail) break; // 当count不足k个的时候，tail会变成NULL，即最后一个子组数量不够，则不用再继续反转了，直接退出循环

            // 反转之后子组之间的连接会断掉，所以要提前备份好它的新尾结点和子组下一个节点，即下一次反转完成后要连接本子组的newTail和下一次循环中子组的头结点newStart
            ListNode *newStart = tail->next;
            ListNode *newTail = pre->next;
            ListNode *reverseHead = reverse(pre->next, tail);
            pre->next = reverseHead; // 让上个子组的尾结点(上组的newTail已被定义为pre)连接到本组的newHead
            newTail->next = newStart; // 将本子组的尾结点备份成下个子组的pre并连接下个子组
            pre = newTail;
        }
        return dummy->next;
    }
    ListNode* reverse(ListNode* head, ListNode* tail) { // 基本与206题的写法一致，返回的是反转之后的newHead
        ListNode *pre = new ListNode(NULL);
        ListNode *cur = head;
        while (pre != tail) { // 这里不能用!head了，因为这段链表是子链表，tail后面可能不是NULL，所以可改为 head != tail->next，或者 pre != tail
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
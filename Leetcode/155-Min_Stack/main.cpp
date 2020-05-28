/*!
 * @brief 最小栈
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * - push(x) -- 将元素 x 推入栈中。
 * - pop() -- 删除栈顶的元素。
 * - top() -- 获取栈顶元素。
 * - getMin() -- 检索栈中的最小元素。
 */

#include <iostream>
#include <vector>

class MinStack {
public:
    /** initialize your data structure here. */
    struct Node {
        int val;
        int min;
        Node *next;
        Node(int _val, Node *_next = NULL) : val(_val), min(val), next(_next) {}
    };
    // 单链表，每次在head->next插入新节点，把之前插入的结点往后顶。
    // 结点中会多有一个数据，即在插入本结点的时候，链表的最小值是多少。
    // 这样做可以在删除结点时，不需要管删除后最小值发生了怎样的变化，直接访问新的head->next->min即可；
    // 包括在插入新结点的时候，只需要拿原来的head->next->min和新结点的val比较一下再更新到新结点的min即可。

    Node *head;

    MinStack() : head(NULL) {
        head = new Node(0);
    }

    void push(int x) {
        Node *tmp = new Node(x, head->next);
        if (head->next && x > head->next->min) {
            tmp->min = head->next->min;
        }

        head->next = tmp;
    }

    void pop() {
        Node *tmp = head->next;
        if (tmp) {
            head->next = tmp->next;
            delete tmp;
        }
    }

    int top() {
        int top = 0;
        if (head->next) {
            top = head->next->val;
        }
        return top;
    }

    int getMin() {
        int min = 0;
        if (head->next) {
            min = head->next->min;
        }
        return min;
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->pop();
    std::cout << "pop: " << obj->top() << std::endl;
    std::cout << "min: " << obj->getMin() << std::endl;
    return 0;
}

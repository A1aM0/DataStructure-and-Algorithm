/*!
 * @brief 设计循环队列
 *
 * @details
 * 设计你的循环队列实现。
 * 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。
 * 它也被称为“环形缓冲器”。
 * 循环队列的一个好处是我们可以利用这个队列之前用过的空间。
 * 在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
 * 但是使用循环队列，我们能使用这些空间去存储新的值。
 * 你的实现应该支持如下操作：
 * MyCircularQueue(k): 构造器，设置队列长度为 k 。
 * Front: 从队首获取元素。如果队列为空，返回 -1 。
 * Rear: 获取队尾元素。如果队列为空，返回 -1 。
 * enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
 * deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
 * isEmpty(): 检查循环队列是否为空。
 * isFull(): 检查循环队列是否已满。
 *
 * @warning
 * 所有的值都在 0 至 1000 的范围内；
 * 操作数将在 1 至 1000 的范围内；
 * 请不要使用内置的队列库。
 */

#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        head = 0; // 头指针记录队头
        tail = 0; // 尾指针记录队尾的下一个位置！！！
        circularQueue.resize(k);
        queueLength = 0; // 记录队列实际有效的长度
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        // 先检查满队
        if (isFull()) return false;
        // 插入
        circularQueue[tail] = value;
        tail = (tail + 1) % circularQueue.size();
        queueLength++;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        // 先检查空队
        if (isEmpty()) return false;
        // 删
        head = (head + 1) % circularQueue.size();
        queueLength--;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return circularQueue[(head) % circularQueue.size()];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        return circularQueue[(tail - 1 + circularQueue.size()) % circularQueue.size()]; // tail指向队尾下一个位置，所以队尾是tail的前一个元素
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return queueLength == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return queueLength == circularQueue.size();
    }

private:
    int head, tail, queueLength;
    vector<int> circularQueue;
};

int main() {

    MyCircularQueue* obj = new MyCircularQueue(3);
    bool param_1 = obj->enQueue(1);
    bool param_2 = obj->enQueue(2);
    bool param_3 = obj->enQueue(3);
    bool param_4 = obj->enQueue(4);
    int param_5 = obj->Rear();
    bool param_6 = obj->isFull();
    bool param_7 = obj->deQueue();
    bool param_8 = obj->enQueue(4);
    int param_9 = obj->Rear();

    return 0;
}

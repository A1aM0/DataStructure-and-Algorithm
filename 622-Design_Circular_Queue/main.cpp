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

/*!
 * @brief 队列
 *
 * 这是一种最简单的队列，具有入队、出队、判断空、查询队头的功能。
 * 但是存在弊端：当入队与出队次数增加后，p_start参数会增加至非常大，并且数组data会占用更大的空间。
 * 所以需要其他的优化。
 */
class MyQueue {
public:
    /// 初始化队列，指向队头的指针为0.
    MyQueue() {
        p_start = 0;
    }

    /// 向队尾插入元素
    /// @param num 想要插入的元素
    /// @return 0表示添加完成
    int addQueue(int num) {
        data.push_back(num);
        return 0;
    }

    int delQueue() {
        if (p_start >= data.size()) return -1;
        p_start ++;
        return 0;
    }

    int front(){
        return data[p_start];
    }

    bool isEmpty(){
        if (p_start < data.size()) return false;
        else return true;
    }

private:
    int p_start;
    std::vector<int> data;
};

/* Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {

    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {

    }

    /** Get the front item from the queue. */
    int Front() {

    }

    /** Get the last item from the queue. */
    int Rear() {

    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {

    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {

    }
};

void testMyQueue(){
    MyQueue q;
    q.addQueue(5);
    q.addQueue(3);
    if (!q.isEmpty()) {
        std::cout << q.front() << std::endl;
    }
    q.delQueue();
    if (!q.isEmpty()) {
        std::cout << q.front() << std::endl;
    }
    q.delQueue();
    if (!q.isEmpty()) {
        std::cout << q.front() << std::endl;
    }
}

int main() {
    testMyQueue();
    return 0;
}

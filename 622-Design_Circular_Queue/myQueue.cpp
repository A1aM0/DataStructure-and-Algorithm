/*!
 * @brief 队列
 *
 * 这是一种最简单的队列，具有入队、出队、判断空、查询队头的功能。
 * 但是存在弊端：当入队与出队次数增加后，p_start参数会增加至非常大，并且数组data会占用更大的空间。
 * 所以需要其他的优化。
 */

#include <iostream>
#include <vector>

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

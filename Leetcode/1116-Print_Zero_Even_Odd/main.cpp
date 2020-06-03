/*!
 * @brief  打印零与奇偶数
 *
 * 假设有这么一个类：
 * class ZeroEvenOdd {
 *     public ZeroEvenOdd(int n) { ... }      // 构造函数
 *     public void zero(printNumber) { ... }  // 仅打印出 0
 *     public void even(printNumber) { ... }  // 仅打印出 偶数
 *     public void odd(printNumber) { ... }   // 仅打印出 奇数
 * }
 *
 * 相同的一个 ZeroEvenOdd 类实例将会传递给三个不同的线程：
 * 线程 A 将调用 zero()，它只输出 0 。
 * 线程 B 将调用 even()，它只输出偶数。
 * 线程 C 将调用 odd()，它只输出奇数。
 *
 * 每个线程都有一个 printNumber 方法来输出一个整数。
 * 请修改给出的代码以输出整数序列 010203040506... ，其中序列的长度必须为 2n。
 */

#include <iostream>
#include <functional>
#include <condition_variable>

class ZeroEvenOdd {
private:
    int n;
    std::condition_variable cv;
    std::mutex mutex;
    bool volatile zeroPrinted = false;
    bool volatile oddPrinted = false;
    bool volatile evenPrinted = false;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n; ++i) {
            std::unique_lock<std::mutex> ul(mutex);
            cv.wait(ul, [&] {
                return !zeroPrinted;
            });
            printNumber(0);
            zeroPrinted = true;
            cv.notify_all();
        }
    }

    void even(std::function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            std::unique_lock<std::mutex> ul(mutex);
            cv.wait(ul, [&] {
                return zeroPrinted && !evenPrinted && oddPrinted;
            });
            printNumber(i);
            zeroPrinted = false;
            evenPrinted = true;
            oddPrinted = false;
            cv.notify_all();
        }
    }

    void odd(std::function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            std::unique_lock<std::mutex> ul(mutex);
            cv.wait(ul, [&] {
                return zeroPrinted && !oddPrinted;
            });
            printNumber(i);
            zeroPrinted = false;
            oddPrinted = true;
            evenPrinted = false;
            cv.notify_all();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

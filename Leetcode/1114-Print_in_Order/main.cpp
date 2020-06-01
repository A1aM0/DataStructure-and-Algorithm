/*!
 * @brief 按序打印
 *
 * 我们提供了一个类：
 * public class Foo {
 *     public void one() { print("one"); }
 *     public void two() { print("two"); }
 *     public void three() { print("three"); }
 * }
 *
 * 三个不同的线程将会共用一个 Foo 实例。
 * 线程 A 将会调用 one() 方法
 * 线程 B 将会调用 two() 方法
 * 线程 C 将会调用 three() 方法
 * 请设计修改程序，以确保 two() 方法在 one() 方法之后被执行，three() 方法在 two() 方法之后被执行。
 */

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

class Foo {
public:
    Foo() {
        one = false;
        two = false;
        three = false;
    }

    void first(std::function<void()> printFirst) {
        one = true;
        std::unique_lock<std::mutex> ul(mu);
        cv.wait(ul,[this]{
            return this->one;
        });
        printFirst(); // printFirst() outputs "first". Do not change or remove this line.
        two = true;
        one = false;
        cv.notify_all();
    }

    void second(std::function<void()> printSecond) {
        std::unique_lock<std::mutex> ul(mu);
        cv.wait(ul,[this]{
            return this->two;
        });
        printSecond(); // printSecond() outputs "second". Do not change or remove this line.
        three = true;
        two = false;
        cv.notify_all();
    }

    void third(std::function<void()> printThird) {
        std::unique_lock<std::mutex> ul(mu);
        cv.wait(ul,[this]{
            return this->three;
        });
        printThird(); // printThird() outputs "third". Do not change or remove this line.
        three = false;
    }

private:
    std::condition_variable cv;
    std::mutex mu;
    bool one, two, three;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

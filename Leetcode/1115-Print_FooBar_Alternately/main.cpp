/*!
 * @brief 交替打印FooBar
 *
 * 我们提供一个类：
 *
 * class FooBar {
 *     public void foo() {
 *         for (int i = 0; i < n; i++) {
 *             print("foo");
 *         }
 *     }
 *
 *     public void bar() {
 *         for (int i = 0; i < n; i++) {
 *             print("bar");
 *         }
 *     }
 * }
 *
 * 两个不同的线程将会共用一个 FooBar 实例。其中一个线程将会调用 foo() 方法，另一个线程将会调用 bar() 方法。
 * 请设计修改程序，以确保 "foobar" 被输出 n 次。
 */

#include <iostream>
#include <functional>
#include <condition_variable>
#include <mutex>

class FooBar {
private:
    int n;
    std::condition_variable cv;
    std::mutex mutex;
    // 当两个线程都要用到某一个变量且该变量的值会被改变时，应该用 volatile 声明，该关键字的作用是防止优化编译器把变量从内存装入 CPU 寄存器中。
    // 如果变量被装入寄存器，那么两个线程有可能一个使用内存中的变量，一个使用寄存器中的变量，这会造成程序的错误执行。
    // volatile 的意思是让编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的值。
    // b的作用是记录foo已经被输出了(true)，才能输出bar
    bool volatile b = false;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> ul(mutex);
            cv.wait(ul, [&]{
                return !this->b;
            });
            printFoo(); // printFoo() outputs "foo". Do not change or remove this line.
            b = true;
            cv.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> ul(mutex);
            cv.wait(ul, [&]{
                return this->b;
            });
            printBar(); // printBar() outputs "bar". Do not change or remove this line.
            b = false;
            cv.notify_all();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

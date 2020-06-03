/*!
 * @brief H2O 生成
 *
 * 现在有两种线程，氢 oxygen 和氧 hydrogen，你的目标是组织这两种线程来产生水分子。
 * 存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。
 *
 * 氢和氧线程会被分别给予 releaseHydrogen 和 releaseOxygen 方法来允许它们突破屏障。
 * 这些线程应该三三成组突破屏障并能立即组合产生一个水分子。
 * 你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。
 *
 * 换句话说:
 * 如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。
 * 如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。
 *
 * 书写满足这些限制条件的氢、氧线程同步代码。
 */

#include <iostream>
#include <functional>
#include <condition_variable>

class H2O {
private:
    int volatile numHydrogen = 0;
    int volatile numOxygen = 0;
    std::condition_variable cv;
    std::mutex mutex;

public:
    H2O() {

    }

    void hydrogen(std::function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> ul(mutex);
        cv.wait(ul, [&] {
            return numHydrogen < 2;
        });
        releaseHydrogen();// releaseHydrogen() outputs "H". Do not change or remove this line.
        numHydrogen++;
        if (numHydrogen == 2 && numOxygen == 1) {
            numHydrogen = 0;
            numOxygen = 0;
            cv.notify_all();
        }
    }

    void oxygen(std::function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> ul(mutex);
        cv.wait(ul, [&] {
            return numOxygen < 1;
        });
        releaseOxygen();// releaseOxygen() outputs "O". Do not change or remove this line.
        numOxygen++;
        if (numHydrogen == 2 && numOxygen == 1) {
            numHydrogen = 0;
            numOxygen = 0;
            cv.notify_all();
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

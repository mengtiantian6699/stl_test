#include <condition_variable>
#include <cstdio>
#include <iostream>
#include <thread>

std::mutex mtx;             // 互斥量
std::condition_variable cv; // 条件变量
bool isReady = false;       // 条件

void waitingThread() {
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock); // 等待条件变量满足
  std::cout << "Condition is satisfied!" << std::endl;
}
void notifyingThread() {
  std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟一些操作
  {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Notifying waiting thread..." << std::endl;
  }
  cv.notify_one(); // 唤醒等待的线程
}

// #define if_print

int main() {
  std::thread t1(waitingThread);
  std::thread t2(notifyingThread);

  t1.join();
  t2.join();

#ifdef if_print

  printf("printf flag is enable!\n");
#else
  printf("printf flag is no enable!\n");

#endif

  return 0;
}

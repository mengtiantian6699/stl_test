

#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

#include <atomic>
#include <iostream>
#include <thread>
std::mutex thread_test1_mutex;
//注意初始化的方法
std::atomic_int cycle_number_{1};
void ThreadTest1() {
  std::cout << "ThreadTest1 thread id is " << std::this_thread::get_id() << std::endl;
  cycle_number_++;
  std::cout << "ThreadTest1 cycle_number_ is " << cycle_number_ << std::endl;
  while (true) {
    std::lock_guard<std::mutex> lock(thread_test1_mutex);
    std::cout << "thread_test 1 running successful! " << std::endl;
    // 线程挂起1s 100ms 2.5s

    std::this_thread::yield(); //当前线程让出CPU，允许其他线程运行
    // std::this_thread::sleep_for(std::chrono::seconds(1));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // std::this_thread::sleep_for(std::chrono::duration<double>(2.5));

    // 休眠到当前时间点后的5秒
    // auto now = std::chrono::system_clock::now();
    // auto sleep_time = now + std::chrono::seconds(5);
    // std::this_thread::sleep_until(sleep_time);
  }
}

void ThreadTest2(int& a, const int* b) {
  cycle_number_++;
  std::cout << "ThreadTest2 cycle_number_ is " << cycle_number_ << std::endl;
  std::cout << "ThreadTest2 thread id is " << std::this_thread::get_id() << std::endl;
  a = *b;
  std::cout << "thread_test 2 running successful! "
            << "a value is:" << a << std::endl;
}

std::mutex thread_test3_mutex;

void ThreadTest3(int& a, const int* b) {
  std::unique_lock<std::mutex> lock(thread_test3_mutex);
  a = *b; // 受到线程锁保护
  while (true) {
    thread_test3_mutex.unlock();
    std::cout << "ThreadTest3 thread id is " << std::this_thread::get_id() << std::endl; // 不受到线程锁的保护

    thread_test3_mutex.lock();

    std::cout << "thread_test 3 a value is " << a << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
  }
}

int main(int argc, char* argv[]) {
  std::cout << "main thread id is " << std::this_thread::get_id() << std::endl;
  std::thread thread_test1(ThreadTest1);
  thread_test1.detach();

  int thread_input_a = 10, thread_input_b = 20;
  // 使用 std::ref 将 thread_input_a 传递给线程时，将其作为引用传递
  std::thread thread_test2(ThreadTest2, std::ref(thread_input_a), &thread_input_b);
  thread_test2.join();

  std::thread thread_test3(ThreadTest3, std::ref(thread_input_a), &thread_input_b);
  thread_test3.detach();

  // join
  // 等待一个线程完成，如果该线程还未执行完毕，则当前线程（一般是主线程）将被阻塞，直到该线程执行完成，主线程才会继续执行。
  // detach
  // 将当前线程与创建的线程分离，使它们分别运行，当分离的线程执行完毕后，系统会自动回收其资源。如果一个线程被分离了，就不能再使用join()函数了，因为线程已经无法被联接了。
  // joinable()
  //判断线程是否可以执行join()函数，返回true/false
  // ThreadTest2(thread_input_a, &thread_input_b);

  while (true) {
    std::this_thread::sleep_for(std::chrono::microseconds(500));
  }
  //直接调用可以传递 如果在线程创建中调用需要使用std::ref输入

  return 0;
}

// thread 的注意事项

// 1线程是在thread对象被定义的时候开始执行的，而不是在调用join()函数时才执行的，调用join()函数只是阻塞等待线程结束并回收资源。
// 2分离的线程（执行过detach()的线程）会在调用它的线程结束或自己结束时自动释放资源。
// 3线程会在函数运行完毕后自动释放，不推荐利用其他方法强制结束线程，可能会因资源未释放而导致内存泄漏
// 4若没有执行join()或detach()的线程在程序结束时会引发异常。

// mutex
// 1将mutex上锁。如果mutex已经被其它线程上锁，那么会阻塞，直到解锁；如果mutex已经被同一个线程锁住，那么会产生死锁。
// 2将mutex解锁，释放其所有权。如果有线程因为调用lock()不能上锁而被阻塞，则调用此函数会将mutex的主动权随机交给其中一个线程；如果mutex不是被此线程上锁，那么会引发未定义的异常。
// 3尝试将mutex上锁。如果mutex未被上锁，则将其上锁并返回true；如果mutex已被锁则返回false。

// 4加锁和解锁的顺序必须相同。
// 5不能在未获得锁的情况下对共享数据进行操作。
// 6由于使用了std::mutex来控制对共享资源的访问，因此可能会对程序的性能造成影响，如果需要优化程序性能，可以考虑使用无锁编程等技术。

// lock_guard
// 1能够确保在作用域结束时自动释放锁资源，避免了手动管理锁的复杂性和可能出现的错误。
// 2自动加锁：在创建std::lock_guard对象时，会立即对指定的互斥量进行加锁操作。这样可以确保在进入作用域后，互斥量已经被锁定，避免了并发访问资源的竞争条件。
// 3自动解锁：std::lock_guard对象在作用域结束时，会自动释放互斥量。无论作用域是通过正常的流程结束、异常抛出还是使用return语句提前返回，std::lock_guard都能保证互斥量被正确解锁，避免了资源泄漏和死锁的风险
// 4适用于局部锁定：由于std::lock_guard是通过栈上的对象实现的，因此适用于在局部范围内锁定互斥量。当超出std::lock_guard对象的作用域时，互斥量会自动解锁，释放控制权。

// unique_lock
// unique_lock在创建对象时立即对指定的互斥量进行加锁操作，确保互斥量被锁定。在对象的生命周期结束时，会自动解锁互斥量。这种自动加锁和解锁的机制避免了手动管理锁的复杂性和可能出现的错误
// 相对于std::lock_guard的自动加锁和解锁，std::unique_lock提供了更灵活的方式。它可以在需要的时候手动加锁和解锁互斥量，允许在不同的代码块中对互斥量进行多次加锁和解锁操作
// std::unique_lock还支持延迟加锁的功能，可以在不立即加锁的情况下创建对象，稍后根据需要进行加锁操作。此外，它还可以与条件变量（std::condition_variable）一起使用，实现更复杂的线程同步和等待机制

// condition_variable
// std::condition_variable是C++标准库中的一个类，用于在多线程编程中实现线程间的条件变量和线程同步。它提供了等待和通知的机制
// 使得线程可以等待某个条件成立时被唤醒，或者在满足某个条件时通知其他等待的线程
//  1wait使当前线程进入等待状态，直到被其他线程通过notify_one()或notify_all(),函数唤醒。该函数需要一个互斥锁作为参数，调用时会自动释放互斥锁，并在被唤醒后重新获取互斥锁。
//  2wait_for()使当前线程进入等待状态，最多等待一定的时间(相对的时间)，直到被其他线程通过notify_one()或notify_all()函数唤醒，或者等待超时。该函数需要一个互斥锁和一个时间段作为参数，返回时有两种情况：等待超时返回std::cv_status::timeout，被唤醒返回std::cv_status::no_timeout
//  3wait_until()使当前线程进入等待状态，直到被其他线程通过notify_one()或notify_all()函数唤醒，或者等待时间达到指定的(绝对时间点)。该函数需要一个互斥锁和一个绝对时间点作为参数，返回时有两种情况：时间到达返回std::cv_status::timeout，被唤醒返回std::cv_status::no_timeout。
//  4notify_one(): 唤醒一个等待中的线程，如果有多个线程在等待，则选择其中一个线程唤醒。
//  5notify_all(): 唤醒所有等待中的线程，使它们从等待状态返回。

// atomic
// 原子操作是最小的且不可并行化的操作。这就意味着即使是多线程，也要像同步进行一样同步操作原子对象，从而省去了互斥量上锁、解锁的时间消耗。
// 使用
// std::atomic可以保证数据在操作期间不被其他线程修改，这样就避免了数据竞争，使得程序在多线程并发访问时仍然能够正确执行
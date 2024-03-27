#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;
#include <set>

// set会自动排序
int main(void) {
  priority_queue<int> my_queue;
  //插入
  //默认大堆顶
  my_queue.push(1);
  my_queue.push(2);
  my_queue.push(3);
  my_queue.push(3);
  my_queue.push(4);
  my_queue.push(4);
  my_queue.push(5);
  std::cout << "my queue size is :" << my_queue.size() << std::endl;
  std::cout << "my queue size is empty :" << my_queue.empty() << std::endl;

  while (!my_queue.empty()) {
    std::cout << "queue value :" << my_queue.top() << std::endl;
    my_queue.pop();
  }
  std::cout << "my queue size is :" << my_queue.size() << std::endl;
  std::cout << "my queue size is empty :" << my_queue.empty() << std::endl;

  priority_queue<int, vector<int>, greater<int>> my_queue2;
  priority_queue<int, vector<int>, greater<int>> my_queue3;

  my_queue2.push(1);
  my_queue2.push(2);
  my_queue2.push(3);
  my_queue2.push(3);
  my_queue2.push(4);
  my_queue2.push(4);
  my_queue2.push(5);
  my_queue2.emplace(5);

  my_queue2.swap(my_queue3);
  std::cout << "my queue 2 size is :" << my_queue2.size() << std::endl;
  std::cout << "my queue 3 size is :" << my_queue3.size() << std::endl;

  while (!my_queue2.empty()) {
    std::cout << "queue value :" << my_queue2.top() << std::endl;
    my_queue2.pop();
  }

  // TOP-K问题

  srand((size_t)time(nullptr));
  vector<int> top_k_vector;
  for (size_t i = 0; i < 100; i++) {
    top_k_vector.push_back(i);
  }
  std::cout << std::endl;
  for (auto iter = top_k_vector.begin(); iter != top_k_vector.end(); iter++) {
    std::cout << " " << *iter;
  }
  priority_queue<int> my_queue4(top_k_vector.begin(), top_k_vector.end());
  std::cout << std::endl;
  for (size_t i = 0; i < 10; i++) {
    if (!my_queue4.empty()) {
      std::cout << "max value is:" << my_queue4.top() << std::endl;
      my_queue4.pop();
    }
  }
  std::cout << std::endl;
  priority_queue<int, vector<int>, greater<int>> my_queue5(top_k_vector.begin(), top_k_vector.end());
  for (size_t i = 0; i < 10; i++) {
    if (!my_queue5.empty()) {
      std::cout << "max value is:" << my_queue5.top() << std::endl;
      my_queue5.pop();
    }
  }
  std::cout << std::endl;
  int kkk = 10;
  priority_queue<int, vector<int>, greater<int>> my_queue6(top_k_vector.begin(), top_k_vector.begin() + kkk);
  for (size_t i = kkk; i < 100; i++) {
    if (top_k_vector[i] > my_queue6.top()) {
      my_queue6.pop();
      my_queue6.push(top_k_vector[i]);
    }
  }

  while (!my_queue6.empty()) {
    std::cout << " max value is: " << my_queue6.top() << std::endl;
    my_queue6.pop();
  }
  return 0;
}
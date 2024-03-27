#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;
#include <set>
// set会自动排序
int main(void) {
  int init_num[5] = {0, 1, 2, 2, 4};
  int init_num_b[8] = {0};

  memcpy(&init_num_b[2], init_num, 6 * sizeof(int));

  for (int i = 0; i < 8; ++i) {
    std::cout << " init_num_b value =" << init_num_b[i] << std::endl;
  }

  set<int> my_set(init_num, init_num + 5);
  set<int> my_set1 = {0, 1, 2, 2, 4};
  //遍历
  for (auto iter = my_set.begin(); iter != my_set.end(); iter++) {
    std::cout << "my set value is:" << *iter << std::endl;
  }
  std::cout << std::endl;
  for (auto iter = my_set1.begin(); iter != my_set1.end(); iter++) {
    std::cout << "my set1 value is:" << *iter << std::endl;
  }
  std::cout << std::endl;

  my_set.insert(3);
  my_set.insert(5);
  my_set.insert(6);

  for (auto iter = my_set.begin(); iter != my_set.end(); iter++) {
    std::cout << "my set value is:" << *iter << std::endl;
  }

  //删除
  my_set.erase(0);
  auto iter = my_set.find(1);
  my_set.erase(iter);
  std::cout << std::endl;

  for (auto iter = my_set.begin(); iter != my_set.end(); iter++) {
    std::cout << "my set value is:" << *iter << std::endl;
  }

  std::cout << "my set size is:" << my_set.size() << std::endl;
  std::cout << "my set is empty:" << my_set.empty() << std::endl;

  std::cout << "my set is count:" << my_set.count(3) << std::endl;

  return 0;
}
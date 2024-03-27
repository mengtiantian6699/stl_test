#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

// c++中有两种类型的容器：顺序容器和关联容器，顺序容器主要有：
// vector、list、deque等。其中vector表示一段连续的内存地址，基于数组的实现，list表示非连续的内存，基于链表实现。
// deque与vector类似，但是对于首元素提供删除和插入的双向支持。关联容器主要有map和set。map是key-value形式的，set是单值。
// map和set只能存放唯一的key值，multimap和multiset可以存放多个相同的key值。

// list是STL实现的双向链表，与向量vector想比，它允许快速的插入和删除，但是随机访问却是比较慢，需要添加头文件#include<
// list>
// deque容器类与vector类似，支持随机访问和快速插入和删除，与vector不同，deque还支持从开始端插入数据：push_front。其余的类似vector操作方法的使用

// Map是STL的一个关联容器，它提供一对一（其中第一个可以称为关键字，每个关键字只能在map中出现一次，第二个可能称为该关键字的值）的数据
// 处理能力，由于这个特性，它完成有可能在我们处理一对一数据的时候，在编程上提供快速通道。这里说下map内部数据的组织，map内部自建一颗红黑树
//，这颗树具有对数据自动排序的功能，所以在map内部所有的数据都是有序的，后边我们会见识到有序的好处

using namespace std;
int main(void) {
  map<int, string> map1; //空map
  // 1.用insert函数插入pair数据
  map1.insert(std::pair<int, string>(1, "meng"));
  // 2.value_type插入
  map1.insert(map<int, string>::value_type(2, "xie"));
  // 3.数组的方式插入

  map1[5] = "shen";
  std::cout << "map1 size  is:" << map1.size() << std::endl;

  // 以上三种用法，虽然都可以实现数据的插入，但是它们是有区别的，当然了第一种和第二种在效果上是完成一样的，用insert函数插入数据，在数据的
  // 插入上涉及到集合的唯一性这个概念，即当map中有这个关键字时，insert操作是插入数据不了的，
  // 但是用数组方式就不同了，它可以覆盖以前该关键字对应的值

  // map的遍历
  //迭代器遍历
  auto map_it = map1.begin();
  while (map_it != map1.end()) {
    std::cout << map_it->first << " ";
    map_it++;
  }
  std::cout << std::endl;
  // map的大小 size()
  std::cout << map1.size() << " ";
  std::cout << std::endl;
  //
  //此处应注意，应该是 for(int nindex = 1; nindex <= nSize; nindex++)
  //而不是 for(int nindex = 0; nindex < nSize; nindex++)
  for (size_t i = 1; i <= map1.size(); i++) {
    cout << map1[i] << endl;
  } //打印的是value的值
  //查找并获取map中的元素
  //
  auto iter = map1.find(4);
  if (iter != map1.end()) {
    std::cout << "find the key" << std::endl;

    std::cout << "find first value is:" << iter->first << " find second value is:" << iter->second << std::endl;

  } else {
    std::cout << "cant find the key" << std::endl;
  }
  //查找
  auto iter2 = map1.lower_bound(4);
  std::cout << "map1 size before is:" << map1.size() << std::endl;
  map1.erase(iter);
  std::cout << "map1 size after is:" << map1.size() << std::endl;
  for (size_t i = 1; i <= map1.size(); i++) {
    cout << map1[i] << endl;
  }
  int n = map1.erase(1); //如果删除了会返回1，否则返回0
  std::cout << "map1 size after is:" << map1.size() << std::endl;
  for (size_t i = 1; i <= map1.size(); i++) {
    cout << map1[i] << endl;
  }
  // map中所有的数据交换swap
  // map中的swap不是一个容器中的元素交换，而是两个容器所有元素的交换。

  // map中的元素是自动按Key升序排序，所以不能对map用sort函数；

  //打印的是value的值
  //查找并获取map中的元素
  //
  //从map中删除元素

  //创建unordered map 并进行初始化
  unordered_map<int, string> my_ordered_map = {{4, "aaa"}, {5, "bbb"}};
  //插入元素

  my_ordered_map[1] = "meng";
  my_ordered_map.insert({2, "xie"});
  my_ordered_map.insert(std::pair<int, string>(3, "shen"));
  my_ordered_map.insert(make_pair(6, "shen"));
  my_ordered_map.emplace(7, "shen"); //直接插入 避免构造
  std::cout << std::endl;
  std::cout << std::endl;
  for (auto iter = my_ordered_map.begin(); iter != my_ordered_map.end(); iter++) {
    std::cout << "my_ordered_map value after insert is:" << iter->first << std::endl;
  }
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "unordered  map load_factor is:" << my_ordered_map.load_factor() << std::endl;
  //强制修改 如果是insert则不可以修改
  my_ordered_map[2] = "hhh";

  std::cout << "unordered  map size is:" << my_ordered_map.size() << std::endl;
  //访问元素
  std::cout << "unordered  map value 2 is:" << my_ordered_map[2] << std::endl;
  std::cout << "unordered  map value 3 is:" << my_ordered_map.at(3) << std::endl;
  //不确定是否存在时,不可以直接访问,否则出错
  // std::cout << "unordered  map value 5 is:" << my_ordered_map[5] << std::endl;

  //查找find count
  auto unordered_map_iter = my_ordered_map.find(2);
  std::cout << "unordered_map_iter 2 first value is:" << unordered_map_iter->first << std::endl;
  std::cout << "unordered_map_iter 2 first value is:" << my_ordered_map.count(3) << std::endl;
  //遍历哈希表

  for (auto iter = my_ordered_map.begin(); iter != my_ordered_map.end(); iter++) {
    std::cout << "my_ordered_map value is:" << iter->second << std::endl;
  }

  //删除
  my_ordered_map.erase(1);

  for (auto iter = my_ordered_map.begin(); iter != my_ordered_map.end(); iter++) {
    std::cout << "my_ordered_map first value is:" << iter->first << std::endl;
  }
  my_ordered_map.erase(unordered_map_iter);
  std::cout << std::endl;
  for (auto iter = my_ordered_map.begin(); iter != my_ordered_map.end(); iter++) {
    std::cout << "my_ordered_map first value is:" << iter->first << std::endl;
  }

  unordered_map<int, string> my_ordered_map2;
  my_ordered_map.swap(my_ordered_map2);
  std::cout << "unordered  map2 size is:" << my_ordered_map2.size() << std::endl;
  std::cout << "unordered  map size is:" << my_ordered_map.size() << std::endl;

  my_ordered_map.clear();
  std::cout << "unordered  map size is:" << my_ordered_map.size() << std::endl;
  //返回容器可以容纳的最大元素数量
  std::cout << "unordered  map size is:" << my_ordered_map.max_size() << std::endl;
  std::cout << "unordered  map load_factor is:" << my_ordered_map.load_factor() << std::endl;

  double aaa = 10, bbb = 20;
  swap(aaa, bbb);

  std::cout << "aaa  value is:" << aaa << std::endl;

  //   STL总共实现了两种不同结构的关联式容器：树型结构与哈希结构。
  //    树型结构的关联式容器主要有四种：map、set、multimap、multiset。这四种容器的共同点是：使用红黑树 /
  //     平衡搜索树作为其底层结构，容器中的元素是一个有序的序列。

  // set 两者的内部实现是一棵红黑树，它们支持的函数基本相同

  // 与map / multimap不同，map /
  //     multimap中存储的是真正的键值对<key, value> ，set中只放value，但在底层实际存放的是由<value, value>
  //       构成的键值对。 set中插入元素时，只需要插入value即可，不需要构造键值对。
  //       set中的元素不可以重复，因此可以使用set进行去重。 使用set的迭代器遍历set中的元素，可以得到有序序列。
  //       set中的元素默认按照小于来比较。 set中查找某个元素，时间复杂度为：O(
  //         l o g 2 N) O(log_2 N) O(log 2 ​ N)。 set中的元素不允许修改。 set中的底层使用**
  //         二叉搜索树(红黑树)
  //         *
  //     *来实现。
  // set底层是key模型的红黑树，底层是不支持修改的。 支持增 删 查不支持修改

  return 0;
}
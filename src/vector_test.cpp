#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

// 容器类是容纳、包含一组元素或元素集合的对象
//顺序容器与关联容器
//七种基本容器：向量（vector）、双端队列（deque）、链表（list）、集合（set）、多重集合（multiset）、映射（map）和多重映射（multimap）
// 向量是动态结构，它的大小不固定，可以在程序运行时增加或减少
// 与数组不同，向量的内存用尽时，向量自动分配更大的连续内存区，将原先的元素复制到新的内存区，并释放旧的内存区；这是向量类的优点

#include <iomanip>
#include <iostream>
#include <vector> //包含向量容器头文件
using namespace std;

typedef struct {
  double a;
  double b;
} struct1;

typedef struct {
  double a;
  double b;
} struct2;

int main(void) {
  struct1 str1;
  struct2 str2;
  str1.a = 2;
  // str2 = str1;
  // vector的初始化
  vector<int> a(10);
  //定义了10个整型元素的向量（尖括号中为元素类型名，它可以是任何合法的数据类型），但没有给出初值，其值是不确定的。
  vector<int> a1(10, 1);
  vector<int> b1(10, 2);
  //定义了10个整型元素的向量,且给出每个元素的初值为1
  vector<int> a2(a1);
  vector<int> a3(a2.begin(), a2.begin() + 3);
  int b[7] = {1, 2, 3, 4, 5, 9, 8};
  vector<int> a4(b, b + 7);
  //查看第一和最后一个值

  cout << "first value :" << a4.front() << " last value :" << a4.back() << endl;
  // assign 相当与clear之后赋值
  a4.assign(7, 2); //或者 a.assign(b.begin(), b.begin()+3);
  for (auto a : a1) {
    std::cout << a << " ";
  }
  cout << endl;
  for (auto b : b1) {
    std::cout << b << " ";
  }
  cout << endl;

  // clear() 清除数据
  //[i] 可以进行查询或者修改
  // empty()判断是否为空
  // pop_back()
  a1.pop_back();
  for (auto a : a1) {
    std::cout << a << " ";
  }
  cout << endl;

  a1.push_back(10);
  for (auto a : a1) {
    std::cout << a << " ";
  }
  cout << endl;
  //用at查询
  std::cout << a1.at(9) << std::endl;
  // push_back()在最后插入

  a1.reserve(100);
  //扩充容量但其size不变
  // resize()将数组大小调整到某一个数值
  // capacity()返回a在内存中总共可以容纳的元素个数 与size()不同
  cout << a1.size() << " " << a1.capacity() << " " << endl;
  // swap 两个向量数据交换
  a1.swap(b1);
  for (auto a : a1) {
    std::cout << a << " ";
  }
  cout << endl;
  for (auto b : b1) {
    std::cout << b << " ";
  }
  cout << endl;
  // insert插入 a.insert(a.begin()+1,5) 插入的位置和要插入的数据
  //迭代器进行查询
  auto it = b1.begin();

  while (it != b1.end()) {
    cout << *it << ",";
    it++;
  }
  cout << endl;
  for (size_t i = 0; i < b1.size(); i++) {
    b1[i] = 10 - i;
    cout << b1[i] << "/";
  }
  cout << endl;

  // sort 数据从小到大排列
  sort(b1.begin(), b1.end());
  it = b1.begin();
  while (it != b1.end()) {
    cout << *it << ",";
    it++;
  }
  // reverse反转
  reverse(b1.begin(), b1.end());
  cout << endl;
  it = b1.begin();
  while (it != b1.end()) {
    cout << *it << ".";
    it++;
  }
  cout << endl;
  // find 找到数据的下标,返回迭代器
  // copy(b1.begin(), b1.end(), a1.begin() + 1);
  vector<int> arr = {1, 68, 515, 48, 5, 5, 8, 4, 48, 1, 2};
  auto it1 = find(arr.begin(), arr.end(), 5);
  if (it1 != arr.end())
    cout << *it1 << endl;
  else
    cout << "没找到" << endl;
  int arr2[] = {1, 68, 515, 48, 5, 5, 8, 4, 48, 1, 2};
  std::cout << "arr2 size " << sizeof(arr2) << " arr2[0] size " << sizeof(arr2[0]) << endl;

  // blog.csdn.net/CUBE_lotus/article/details/119044709
  // cout < < < < endl;
  // cout << b1.find(5) << endl;
  //
  // cout << endl;
  //将a的容量（capacity）扩充至100，也就是说现在测试a.capacity();的时候返回值是100.这种操作只有在需要给a添加大量数据的时候才
  //显得有意义，因为这将避免内存多次容量扩充操作（当a的容量不足时电脑会自动扩容，当然这必然降低性能）

  //拷贝构造
  return 0;
}
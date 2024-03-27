#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
//  <numeric> 体积很小，只包括几个在序列上进行简单数学运算的模板函数
// <functional> 定义了一些类模板，用以声明函数对象
// <algorithm> 是所有stl头文件中最大的一个，涉及比较，交换，查找，遍历，复制，修改等操作

// 仿函数（Functor）又称为函数对象（Function
//   Object）是一个能行使函数功能的类。仿函数的语法几乎和我们普通的函数调用一样，不过作为仿函数的类，都必须重载
//   operator() 运算符。因为调用仿函数，实际上就是通过类对象调用重载后的
//   operator() 运算符。
using namespace std;
class Comp {
public:
  Comp(double val) : a(val) {}
  bool operator()(int val2) { return val2 > a; }

private:
  double a;
};

void print1(int val) { cout << val << " "; }
int input(int val) { return val * 2; }
bool compare_(int value) { return value > 15; }
bool sort_(int val1, int val2) { return val1 <= val2; }

int main(void) {
  // 常用遍历算法
  //! 1.1for_each遍历容器
  //输入为初始和结束位置  以及操作函数
  std::vector<int> vec;
  for (size_t i = 0; i < 10; i++) {
    vec.push_back(i);
  }

  for_each(vec.begin(), vec.end(), print1);
  cout << endl;
  //! 1.2 transform
  //功能：搬运容器到另一个容器中
  std::vector<int> vec1;
  vec1.resize(vec.size());
  transform(vec.begin(), vec.end(), vec1.begin(), input);
  for_each(vec1.begin(), vec1.end(), print1);
  cout << endl;
  //查找
  // !2.1 find 功能描述：查找指定元素，找到返回元素的迭代器，找不到返回结束迭代器end（）
  vector<int>::iterator it = find(vec.begin(), vec.end(), 6);
  if (it == vec.end()) {
    cout << "没有找到" << endl;
  } else {
    cout << "找到了" << *it << endl;
  }
  //! 2.2 find_if 按值查找元素，找到返回指定位置迭代器，找不到返回end迭代器
  it = find_if(vec1.begin(), vec1.end(), compare_);
  if (it == vec1.end()) {
    cout << "没有找到" << endl;
  } else {
    cout << "找到了" << *it << endl;
  }
  //! binary_search  查找指定元素是否存在 	bool it = binary_search(v.begin(), v.end(),10);
  //! adjacent_find 查找相邻重复元素，返回相邻元素的第一个位置迭代器   vector<int>::iterator it =
  //! adjacent_find(v.begin(), v.end());
  //计算元素个数
  //! count 统计元素个数 count（iterator beg，iterator end，value）
  int number_count = count(vec.begin(), vec.end(), 2);
  std::cout << " count number value is:" << number_count << std::endl;
  //!按照条件查找元素的个数 count_if（iterator beg，iterator end，pred_）
  number_count = count_if(vec1.begin(), vec1.end(), compare_);
  std::cout << " 15 value is:" << number_count << std::endl;
  //排序
  //! 3.1 sort 对容器内元素进行排序
  sort(vec1.begin(), vec1.end(), sort_); // sort_升或者降都可以
  for_each(vec1.begin(), vec1.end(), print1);
  cout << endl;

  //! 3.2指定范围内元素随机调整次序
  srand((unsigned int)time(NULL)); //随机数种子
  random_shuffle(vec1.begin(), vec1.begin());
  for_each(vec1.begin(), vec1.end(), print1);
  cout << endl;
  //! 3.3 merge两个容器元素合并，并存储到另一个容器中 merge（iterator beg1，iterator end1，iterator beg2，iterator
  //! end2，iterator dest）
  //且自动排序
  std::vector<int> vec2;
  vec2.resize(vec.size() + vec1.size());
  merge(vec.begin(), vec.end(), vec1.begin(), vec1.end(), vec2.begin());
  for_each(vec2.begin(), vec2.end(), print1);
  cout << endl;
  // reverse 反转
  reverse(vec2.begin(), vec2.end());
  for_each(vec2.begin(), vec2.end(), print1);
  cout << endl;
  //常用拷贝和替换算法
  //! 4.1 copy 容器中指定范围的元素拷贝到另一个容器中
  copy(vec.begin(), vec.end(), vec2.begin());
  for_each(vec2.begin(), vec2.end(), print1);
  cout << endl;
  // !4.2 replace将容器内指定范围的旧元素修改为新元素
  //将容器内指定范围的旧元素修改为新元素
  replace(vec2.begin(), vec2.end(), 2, 200);
  for_each(vec2.begin(), vec2.end(), print1);
  cout << endl;
  //! 4.3 replace_if 将区间内满足条件的元素，替换成指定元素
  replace_if(vec2.begin(), vec2.end(), compare_, 0);
  for_each(vec2.begin(), vec2.end(), print1);
  cout << endl;
  //! 4.4 swap 交换两个容器中的内容
  swap(vec2, vec1);
  for_each(vec2.begin(), vec2.end(), print1);
  cout << endl;
  for_each(vec1.begin(), vec1.end(), print1);
  cout << endl;
  //! 5.1 accumulate  计算容器内元素累计总和 最后的数值是初始值
  std::cout << "accumulate value is: " << accumulate(vec1.begin(), vec1.end(), 10) << endl;
  //! 5.2 fill 填充数据
  std::cout << "vec1 size is: " << vec1.size() << endl;
  fill(vec1.begin(), vec1.end(), 2);
  for_each(vec1.begin(), vec1.end(), print1);
  cout << endl;

  // set_intersection 求两个容器交集
  // set_union 求两个容器并集
  // set_difference 求两个容器差集
  //! 6.1 求set_intersection（iterator beg1，iterator end1，iterator beg2，iterator end2，iterator beg3）
  sort(vec.begin(), vec.begin());
  for_each(vec.begin(), vec.end(), print1);
  cout << endl;
  for_each(vec1.begin(), vec1.end(), print1);
  cout << endl;
  std::vector<int> vec3;
  vec3.resize(vec.size() + vec1.size());
  it = set_intersection(vec.begin(), vec.end(), vec1.begin(), vec1.end(), vec3.begin());
  for_each(vec3.begin(), it, print1);
  cout << endl;
  std::cout << "vec3 size is: " << vec3.size() << endl;
  cout << endl;
  // 6.2 并集 set_union（iterator beg1，iterator end1，iterator beg2，iterator end2，iterator beg3）
  it = set_union(vec.begin(), vec.end(), vec1.begin(), vec1.end(), vec3.begin());
  for_each(vec3.begin(), it, print1);
  cout << endl;
  // 6.3 set_difference 求两个容器差集

  it = set_difference(vec.begin(), vec.end(), vec1.begin(), vec1.end(), vec3.begin());
  for_each(vec3.begin(), it, print1);
  cout << endl;
  Comp comp(8.0);
  for_each(vec2.begin(), vec2.end(), print1);
  std::cout << "  大于10的个数为:" << count_if(vec2.begin(), vec2.end(), comp);
  cout << endl;
  return 0;
}

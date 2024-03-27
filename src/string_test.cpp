#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
// C语言中，字符串是以 '\0'结尾的一些字符的集合，为了操作方便，C标准库中提供了一些str系列的库函
// 数，但是这些库函数与字符串是分离开的，不太符合OOP的思想，而且底层空间需要用户自己管理，稍不留神可能还会越界访问。
// oop思想：
//   指的是面向对象编程
// 用字符串的方式赋值比字符逐个赋值要多占一个字节，多占的这个字节用于存放字符串结束标志’\0,
//   上面的数组c在内存中的实际存放情况 h e l l o w o r l d \0

// 数组的初始化一般有2种方法

// 第一种也是常用的聚合方式赋值

// int a[] = {1, 2, 3, 4, 5, 6}

// 第二种是单一数组元素赋值

//   int a[];

// a[0] = 1;

// a[1] = 2;

// a[2] = 3;

// cout << sizeof(aar) / sizeof(aar[0]) << endl; 长度的计算
// int aar[] = {1, 2, 3, 4, 5, 6};
// for (int value : aar)
//   ;

// 数组参数传递给函数时，会自动转换为指向数组第一个元素的指针。因此，int arr[] 和 int *arr
//   在函数参数中是等效的。函数内部使用指针的方式来访问数组元素。

//!传递数组的指针 数组形式的参数会被隐式地转换为指针。 因此，int arr[] 和 int *arr 在函数参数中是等效的
void printout(char ch[]) {
  for (size_t i = 0; i < 5; i++) {
    /* code */
    printf("single %zu value is %c:\n", i, ch[i]);
    // std::cout << ch[i] << " " << std::endl;
  }
}

void printout0(char ch[5]) {
  for (size_t i = 0; i < 5; i++) {
    /* code */
    printf("single %zu value is %c:\n", i, ch[i]);
    // std::cout << ch[i] << " " << std::endl;
  }
}
//!传递数组的指针 同上
void printout2(char *ch) {
  for (size_t i = 0; i < 5; i++) {
    /* code */
    printf("single %zu value is %c:\n", i, ch[i]);
    // std::cout << ch[i] << " " << std::endl;
  }
}
//! 传递数组的引用 传递数组的引用时 其大小必须与传递的数组大小相同
void printout3(char (&ch)[15]) {
  printf(" printout3 size of char is %lu \n", sizeof(ch) / sizeof(ch[0]));
  for (size_t i = 0; i < 5; i++) {
    /* code */
    printf(" printout3 single %zu value is %c:\n", i, ch[i]);
    // std::cout << ch[i] << " " << std::endl;
  }
}
//! 你定义了一个引用 char &ch，表示这是一个对单个字符的引用，而不是对字符数组的引用;
//!需要指定其大小
void printout4(char &ch) {
  printf(" printout3 size of char is %lu \n", sizeof(ch));
  for (size_t i = 0; i < 5; i++) {
    /* code */
    printf(" printout3 single %zu value is %c:\n", i, ch);
    // std::cout << ch[i] << " " << std::endl;
  }
}
//同 printout和 printout2
// 对于 void printout5(char ch[8]);
// 和 void printout(char ch[]);
// ，传递任何大小的字符数组都是有效的
void printout5(char ch[8]) {
  printf(" printout3 size of char is %lu \n", sizeof(ch) / sizeof(ch[0]));
  for (size_t i = 0; i < 5; i++) {
    /* code */
    printf(" printout3 single %zu value is %c:\n", i, ch[i]);
    // std::cout << ch[i] << " " << std::endl;
  }
}

int main() {
  // int ch_int[]; //不可以直接这样定义 需要指定其大小  或者定义时候初始化
  //! 数组的初始化和循环
  int ch_int[] = {7, 8, 9, 10, 11, 12};
  string s1("hello wo"); //有参构造

  for (auto ch : ch_int) {
    printf("value is: %d \n", ch);
  }

  char ch[15] = "abcedfg";
  // //!数组名可以被视为指向数组首元素的指针 可以使用*(ch + i)取第i元素的值
  for (int i = 0; i < 5; ++i) {
    std::cout << *(ch + i) << " ";
  }
  std::cout << std::endl;
  std::cout << "size of ch[10] is " << sizeof(ch) / sizeof(ch[0]) << std::endl;
  printout3(ch);
  printout2(ch);
  printout(ch);

  strncpy(ch, s1.c_str(), sizeof(ch));
  //!标准的写法
  // strncpy(ch, s1.c_str(), sizeof(ch) - 1);
  // ch[sizeof(ch) - 1] = '\0'; // 确保字符串以空字符结尾
  std::cout << "after strncpy ch value is :" << ch << "size is" << sizeof(ch) << std::endl;
  //

  // std::cout << "char value is :" <<
  // ch << std::endl;
  // string的构造
  string s;      //无构造 空
  string s2(s1); //拷贝构造
  std::cout << "s capcity is :" << s.capacity() << std::endl;
  // cout << s1.size() << endl; // s1.length()

  //! 2 string 的数据读写
  //? 下标读写
  for (size_t i = 0; i < s1.size(); i++) { //! size() 得到字符串的大小
    cout << s1[i] << ' ';
  }
  cout << endl;
  // string 的数据访问 at()
  for (size_t i = 0; i < s1.size(); i++) {
    cout << s1.at(i) << ' ';
  }
  cout << endl;
  //?迭代器
  string::iterator s1_it = s1.begin(); //! begin 指向字符串开头的迭代器

  while (s1_it != s1.end()) { //! begin 末尾的迭代器

    cout << *s1_it; //! *迭代器 输出里边的内容
    s1_it++;        //!迭代器加加 指向下一个字符的迭代器
  }
  cout << endl;
  //反像输出不能直接begin和end调换 需要用反向迭代器
  string::reverse_iterator it = s1.rbegin();
  while (it != s1.rend()) {
    cout << *it;
    it++;
  }
  cout << endl;

  // const正向迭代器 只读
  // string::const_iterator it = s1.begin();
  // while (it != s1.end()) {
  //   cout << *it;
  //   it++;
  // }
  //! for  循环
  //不可修改
  for (auto x : s1) {
    cout << x << ' ';
  }
  //
  cout << endl;

  for (auto &x : s1) {
    cout << x << ' ';
    x = '1'; //其中的1个字符  “ ”里面的是字符串
  }
  //
  cout << endl;

  for (auto x : s1) {
    cout << x << ' ';
  }
  cout << endl;

  string s3("hello world");
  //! empty判断是否为空
  if (s.empty()) {
    std::cout << "s 为空";
  }
  cout << endl;
  //! clear清楚 清除之后字符串为空

  s3.clear();
  if (s3.empty()) {
    std::cout << "s3 为空";
  }
  cout << endl;
  //改变其大小
  string s4("hello world");

  s4.resize(5); //相当于截断
  for (auto x : s4) {
    cout << x << ' ';
  }
  cout << endl;

  std::cout << s4.size() << std::endl;
  string ss1("hello world"); //有参构造
  string ss2("11111");       //拷贝构造
  std::cout << ss1 + ss2 << std::endl;

  // insert 插入字符
  ss1.insert(6, 4, 'z'); //从第六个字符插入4个z
  std::cout << ss1 << std::endl;
  // replase 替换
  // assign清空赋值
  ss1.assign("222222");
  ss2 = ss1;
  std::cout << ss1 << std::endl;
  std::cout << ss2 << std::endl;
  // erase删除
  string sss1 = "hello world";
  sss1.erase(0, 3); // 删除0~3
  cout << sss1 << endl;

  string sss2 = "hello world";
  sss2.erase(3); //  删除3~后面全部
  cout << sss2 << endl;

  // reverse反转
  string sss3 = "hello world";

  reverse(sss3.begin(), sss3.end());
  std::cout << sss3 << std::endl;

  //字符串相关接口
  // c_str()返回的是一个字符串
  std::cout << sss3.c_str() << std::endl;
  // find 寻找匹配的字符串的下标
  string str = "The apple thinks apple is delicious"; //长度34
  string key = "apple";

  // s.find(str)            查找字符串str在当前字符串s中第一次出现的位置
  int pos1 = str.find(key);
  if (pos1 != -1) std::cout << pos1 << std::endl;
  if (pos1 != str.npos) std::cout << pos1 << std::endl;

  // substr 获得指定位置的字符串

  std::cout << str.substr(3) << std::endl;     // 3到最后
  std::cout << str.substr(3, 10) << std::endl; // 3到10

  // getline得到一整行字符串
  return 0;
}
/*
output: The t1 has elements: 5
*/

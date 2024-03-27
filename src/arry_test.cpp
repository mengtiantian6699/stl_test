#include <algorithm>
#include <cstring>
#include <iostream>

//!传递数组的指针 数组形式的参数会被隐式地转换为指针。 因此，int arr[] 和 int *arr 在函数参数中是等效的
void printout1(char ch[]) {
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

int main(int argc, char *argv[]) {
  // 定义并初始化整型数组
  int array1[5] = {1, 2, 3, 4, 5};
  // 定义并初始化字符串数组
  char array2[] = "Hello";

  // 输出整型数组的元素
  std::cout << "Integer Array: ";
  for (int i : array1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  // 输出字符串数组的元素
  std::cout << "String Array: " << array2 << std::endl;
  //初始化为0
  int arr[5];
  std::fill(std::begin(arr), std::end(arr), 0);
  int arr2[5];
  std::memset(arr2, 0, sizeof(arr2));

  //   int arr[5] = {};
  //   和 int arr[5] = {0};
  //   都会将数组全部初始化为0。 int arr[5] = {1};
  //   只会将数组的第一个元素初始化为1，其余元素会被默认初始化为0。
  int arr3[5] = {};
  int arr4[5] = {0};
  int arr5[5] = {1};

  int init_num[5] = {0, 1, 2, 2, 4};
  int init_num_b[8] = {0};

  memcpy(&init_num_b[2], init_num, 6 * sizeof(int));
  memcpy(&init_num_b[0], init_num, 6 * sizeof(int));
  memcpy(&init_num_b, &init_num, 6 * sizeof(int));
  memcpy(init_num_b, init_num, 6 * sizeof(int));
  //   memcpy 用于复制任意内存块的内容，而 strncpy
  //   主要用于复制字符串，且可以指定最大复制长度和在复制不足的情况下自动补0。
  //   strncpy

  char *p = "aaaaaaaaaaaaaa";
  char ip1[] = "bbbbbbbbbbb";
  char ip2[80] = "192.168.1.1";
  printout0(p);
  printout1(p);
  printout2(p);

  printout0(ip1);
  printout1(ip1);
  printout2(ip1);

  //   char *p = "192.168.1.1";
  //   这个语句是正确的，因为字符串字面值
  //     "192.168.1.1" 实际上是一个字符数组的地址，它以空字符 '\0' 结尾，因此可以赋给指向字符的指针 char *p。这个指针
  //     p
  //       指向了字符串的第一个字符

  return 0;
}
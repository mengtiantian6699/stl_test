#include <iostream>
#include <tuple>

// ​ std::tuple是C++
// 11新标准引入的一个类模板，又称为元组，是一个固定大小的异构值集合，由std
// ::
// pair泛化而来。pair可以看作是tuple的一种特殊情况，成员数目限定为两个。tuple可以有任意个成员数量，但是每个确定的tuple类型的成员数目是固定的。

//   ​
//从概念上讲，它们类似于C的结构体，但是不具有命名的数据成员，我们也可以把他当做一个通用的结构体来用，不需要创建结构体又获取结构体的特征，在某些情况下可以取代结构体使程序更简洁，直观。

int main() {
  // tuple 的构造
  std::tuple<std::string, int> t1;     //无参构造
  std::tuple<std::string, int> t2(t1); //拷贝构造
  std::tuple<std::string, int> t3(std::make_tuple("Lily", 1));
  std::tuple<std::string, long> t4(t3);                       //隐式类型转换构造的左值方式
  std::tuple<std::string, int> t5("Mike", 2);                 //初始化列表构造的右值方式
  std::tuple<std::string, int> t6(std::make_pair("Jack", 3)); //将pair对象转换为tuple对象
  // make_tuple 创建右值对象
  std::tuple<std::string, double, int> t7 = std::make_tuple("Jack", 66.6, 88);
  auto t8 = std::make_tuple(1, "Lily", 'c');
  //获取tuple的值 std::get 或者 std::tie
  std::cout << '(' << std::get<0>(t3) << ',' << std::get<1>(t3) << ',' << ')' << '\n';
  std::string name;
  double value; //数据类型不一样时可以转化,但是string类型不能传入其他类型
  std::tie(name, value) = t6;
  std::cout << '(' << name << ',' << value << ',' << ')' << '\n';
  // std:;ignore
  std::tie(std::ignore, value) = t5;
  //修改tuple中的数值
  std::get<0>(t5) = "meng";
  std::cout << '(' << std::get<0>(t5) << ')' << '\n';

  std::cout << '(' << value << ')' << '\n';
  //获取元素的个数
  auto t9 = std::make_tuple(2, "MAX", 999, 888, 65.6);
  std::cout << "The t1 has elements: " << std::tuple_size<decltype(t1)>::value << '\n';
  //获取元素类型 std::tuple<size_t i,decltype(tuple)>::type

  return 0;
}
/*
output: The t1 has elements: 5
*/

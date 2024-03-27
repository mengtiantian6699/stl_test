#include <fstream> //ifstream 头文件
#include <iostream>
#include <sstream> //istringstream 头文件
#include <vector>
//如果需要赋值给相应的变量 需要使用 map存储数据 再进行find查询
std::vector<std::string> ParameterLoading(const std::string &config_path) {
  std::ifstream configFile;
  std::string line;
  configFile.open(config_path.c_str());
  if (!configFile) {
    printf("can not found config path!!! \n");
    exit(0);
  }
  std::vector<std::string> key_vec;
  std::vector<std::string> value_vec;
  while (std::getline(configFile, line)) {
    std::istringstream iss(line);
    std::string key, value;
    if (std::getline(iss, key, '=') && std::getline(iss, value)) {
      key_vec.push_back(key);
      value_vec.push_back(value);
    }
  }
  configFile.close();
  return value_vec;
}

int main() {
  std::string inputString = "123 4.56 hello";
  std::istringstream iss(inputString);

  int intValue;
  float floatValue;
  std::string stringValue;

  iss >> intValue;
  //   std::cout << iss << std::endl;

  iss >> floatValue;
  iss >> stringValue;

  std::cout << "Int: " << intValue << ", Float: " << floatValue << ", String: " << stringValue << std::endl;

  return 0;
}

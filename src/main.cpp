#include <glog/logging.h>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <sys/select.h>
#include <unistd.h> // 包含 usleep 所在的头文件
#include <cctype>   // 包含 isdigit 和 isalpha 所在的头文件
#include <chrono>
#include <cstdint>
#include <ctime>
#include <fstream>
#include <iomanip> // 包含 setprecision 所在的头文件
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include "test.h"
// #include "spdlog/sinks/basic_file_sink.h" //for basic file logger

#define TEST_INFO(...)                             \
  do {                                             \
    printf("INFO[%f]:", GetNowTimeSecInterface()); \
    printf(__VA_ARGS__);                           \
    printf("\n");                                  \
  } while (0)
#define TEST_WARN(...)                             \
  do {                                             \
    printf("WARN[%f]:", GetNowTimeSecInterface()); \
    printf(__VA_ARGS__);                           \
    printf("\n");                                  \
  } while (0)
#define TEST_ERROR(...)                             \
  do {                                              \
    printf("ERROR[%f]:", GetNowTimeSecInterface()); \
    printf(__VA_ARGS__);                            \
    printf("\n");                                   \
  } while (0)
static inline double GetNowTimeSecInterface() {
  auto currentTimePoint2 = std::chrono::high_resolution_clock::now();
  auto microseconds =
    std::chrono::duration_cast<std::chrono::microseconds>(currentTimePoint2.time_since_epoch()).count();
  return static_cast<double>(microseconds) / 1000.0 / 1000.0;
}

//! 判断string是不是纯数字
static bool isNumeric(const std::string& str) {
  bool hasDot = false;

  for (char c : str) {
    if (std::isdigit(c)) {
      // 是数字
    } else if (c == '.') {
      if (hasDot) {
        return false; // 多个小数点，不是合法数字
      }
      hasDot = true;
    } else if (c == '+' || c == '-') {
      // 正负号只能出现在第一个字符处
      if (&c != &str[0]) {
        return false;
      }
    } else {
      return false; // 非数字、小数点、正负号的字符，不是合法数字
    }
  }

  return true; // 符合数字的规则
}

// 至少包含一个数字且可能包含小数点，才认为是浮点数

//! 读取CSV文件

static std::vector<std::vector<double>> ReadDataFromCSV(const std::string& file_path) {
  std::ifstream inputFile(file_path.c_str());
  std::vector<std::vector<double>> csvNumericData;

  // 检查文件是否成功打开
  if (!inputFile.is_open()) {
    std::cerr << "Error opening the file." << std::endl;
    return csvNumericData;
  }

  // 定义一个二维向量存储 CSV 数字数据

  // 逐行读取 CSV 文件
  std::string line;
  while (std::getline(inputFile, line)) {
    for (char& i : line) {
      if (i == ',') {
        i = ' ';
      }
    }
    std::istringstream lineStream(line);
    std::string cell;
    std::vector<double> row;

    // 以逗号为分隔符解析每个单元格
    while (lineStream >> cell) {
      // 将解析的字符串转换为 double
      if (isNumeric(cell)) {
        row.push_back(std::stod(cell));
      }
    }
    if (row.empty()) {
      continue;
    }
    // 将一行数据存储到二维向量中
    csvNumericData.push_back(row);
  }

  // 关闭文件
  inputFile.close();
  return csvNumericData;
}

//<1.创建名称为LoggerName1、内容输出到控制台的单线程版本日志记录器
// auto logger1 = spdlog::stdout_color_st("LoggerName1");

//<2.创建名称为LoggerName2、内容输出到Logs/BasicFileLog.txt的多线程版本日志记录器
// auto logger2 = spdlog::basic_logger_mt("LoggerName2", "Logs/BasicFileLog.txt");

//<3.创建名称为LoggerName3、内容输出到Logs/RotatingFileLog.txt的多线程版本日志记录器
//参数1024*1024*5设置了文件最大容量为5mb，参数3设置了文件最大数量为3
//当日志文件存储超过5mb时，将重命名日志文件并且新增另外一个日志文件
//当日志文件数量超过3时，将删除第一个日志文件

// auto logger3 = spdlog::rotating_logger_mt("LoggerName3", "Logs/RotatingFileLog.txt", 1024 * 1024 * 5, 3);

//<4.创建名称为LoggerName4、内容输出到Logs/DailyFileLog.txt的多线程版本日志记录器
//参数2和30指定每天生成日志文件的时间为凌晨2点30分

// auto logger4 = spdlog::daily_logger_mt("LoggerName4", "Logs/DailyFileLog.txt", 2, 30);

uint64_t cycle_number_ = 0;
int main(int argc, char* argv[]) {
  HMI_SEND_TO_CAR_TOPIC_TEST aaa;
  HMI_SEND_TO_CAR_TOPIC bbb;

  aaa.APA_ParkingDir_Req = 5;

  memcpy(&bbb.APASwitch, &aaa, sizeof(aaa));

  std::cout << "bbb req is :" << (int)bbb.APA_ParkingDir_Req << std::endl;
  std::cout << "HMI_SEND_TO_CAR_TOPIC size is " << sizeof(HMI_SEND_TO_CAR_TOPIC) << std::endl;
  std::cout << "HMI_SEND_TO_CAR_TOPIC_TEST size is " << sizeof(HMI_SEND_TO_CAR_TOPIC_TEST) << std::endl;

  std::cout << "MessageHeader size is " << sizeof(MessageHeader) << std::endl;

  // google::InitGoogleLogging("test_log");
  // FLAGS_alsologtostderr = false; // 将日志同时输出到标准错误流和文件

  // FLAGS_log_dir = "../log";
  // FLAGS_minloglevel = google::GLOG_WARNING; // 设置最小输出级别为 WARNING
  // FLAGS_logbufsecs = 0;                     // 立即刷新到文件
  // FLAGS_logbuflevel = -1;                   // 设置输出缓冲区的级别，-1 表示所有级别都缓冲
  // INITLOG("path");
  // auto logger = spdlog::basic_logger_mt("file_logger", "../log/basic-log.txt");
  // logger->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [thread %t] %v (%s:%#)");

  // // auto logger = spdlog::basic_logger_mt("file_logger", "../log/basic-log.txt");
  // auto logger1 = spdlog::basic_logger_mt("file_logger1", "../log/basic-log1.txt");
  // logger->set_level(spdlog::level::trace); // 设置日志等级为debug

  // // trace debug info warn err critical off
  // logger->flush_on(spdlog::level::trace);
  // logger1->flush_on(spdlog::level::trace);

  int a = 10;
  float b = 10.2;
  std::string name = "Tom";

  // logger->info("a = {}", a);
  // logger->error("b = {}", b);
  // logger->info("name = {}", name);

  // logger1->info("a = {}", a);
  // logger1->error("b = {}", b);
  // logger1->info("name = {}", name);

  // FLAGS_logtostderr = true; // 将日志输出到标准错误流
  { //! FLAGS_alsologtostderr不设置的时候 只输出到文件
    //! FLAGS_log_dir配置文件输出的路径
    //!  FLAGS_logbufsecs立即刷新到文件
    //! FLAGS_logbuflevel 设置输出缓冲区的级别，-1 表示所有级别都缓冲
  } // 设置日志输出目录
  // google::SetLogDestination(google::GLOG_WARNING, "../log/warning.log");
  // google::SetLogDestination(google::GLOG_WARNING, "../log/information.log");
  // LOG(WARNING) << "This is an warning ." << cycle_number_;
  // LOG(ERROR) << "This is an error ." << cycle_number_;
  // LOG(INFO) << "This is an info ." << cycle_number_;
  // 获取当前时间点
  while (true) {
    // logger->info("name = {}", name);

    cycle_number_++;
    // LOG(WARNING) << "This is an warning ." << cycle_number_;
    // LOG(ERROR) << "This is an error ." << cycle_number_;
    // LOG(INFO) << "This is an info ." << cycle_number_;

    // LOG(FATAL) << "This is a fatal error message.";

    { //!获取系统时间(s) 头文件<chrono>
      auto currentTimePoint = std::chrono::system_clock::now();
      // 将时间点转换为时间戳（以秒为单位）
      std::time_t currentTime = std::chrono::system_clock::to_time_t(currentTimePoint);
      // 输出时间戳
      TEST_INFO("Current time:%ld", currentTime);
    }

    {
      //! 获取系统时间us 头文件<chrono>
      auto currentTimePoint2 = std::chrono::high_resolution_clock::now();

      // 计算时间点的微秒数
      auto microseconds =
        std::chrono::duration_cast<std::chrono::microseconds>(currentTimePoint2.time_since_epoch()).count();
      TEST_INFO("Current time in microseconds is :%ld", microseconds);
      uint64_t microseconds_61_t = microseconds;
      TEST_INFO("microseconds_61_t is :%ld", microseconds_61_t);
    }

    { //!使程序挂起 1000ms 头文件cstdint
      usleep(1000 * 1000);
    }

    { //!使程序挂起 20ms 头文件thread
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    { //!设置输出的精度 头文件iomanip
      double pi = 3.14159265358979323846;
      std::cout << "Value of pi: " << std::fixed << std::setprecision(8) << pi << std::endl;
    }

    {
      std::string file_path = "../data/mytestdata.csv";
      auto csv_data = ReadDataFromCSV(file_path);
      TEST_INFO("读取文件的大小为：%zu", csv_data.size());
    }
  }
  // google::ShutdownGoogleLogging();
  return 0;
}

#include <spdlog/common.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <unistd.h>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <memory>
#include <ostream>

int main() {
  // 创建终端日志 sink
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

  // 创建文件日志 sink，输出到 example.log 文件
  auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../log/example.log", true);

  // 创建 logger，并添加两个 sinks
  auto logger = std::make_shared<spdlog::logger>("my_logger", spdlog::sinks_init_list{console_sink, file_sink});

  // 设置日志级别
  logger->set_level(spdlog::level::trace);
  logger->flush_on(spdlog::level::info);
  uint64_t cycle_number_ = 0;
  // 使用 logger 记录日志
  while (true) {
    std::cout << std::endl;
    cycle_number_++;

    if (cycle_number_ >= 3) {
      logger->set_level(spdlog::level::warn);
    }
    logger->trace("This is a trace message");
    logger->debug("This is a debug message");
    logger->info("This is an info message");
    logger->warn("This is a warning message");
    logger->error("This is an error message");
    usleep(1000 * 1000);
  }
  return 0;
}

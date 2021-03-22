//[timepoint
#include <binlog/adapt_stdtimepoint.hpp> // must be included to log std::chrono::system_clock::time_point
//]

#include <binlog/binlog.hpp>

#include <chrono>
#include <iostream>

int main()
{
  //[timepoint

  std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
  //]

  // use microseconds instead of nanoseconds because of macOS
  now = std::chrono::system_clock::time_point(std::chrono::microseconds{1615917902123456});

  //[timepoint
  BINLOG_INFO("Now: {}", now);
  // Outputs: Now: 2021-03-16 18:05:02.123456000
  //]

  binlog::consume(std::cout);
  return 0;
}

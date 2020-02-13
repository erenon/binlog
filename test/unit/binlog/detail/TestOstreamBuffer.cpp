#include <binlog/detail/OstreamBuffer.hpp>

#include <boost/test/unit_test.hpp>

#include <cstdint>
#include <sstream>

namespace {

struct TestcaseBase
{
  std::ostringstream str;
  binlog::detail::OstreamBuffer buf{str};

  std::string result()
  {
    buf.flush();
    return str.str();
  }
};

} // namespace

BOOST_AUTO_TEST_SUITE(OstreamBuffer)

BOOST_FIXTURE_TEST_CASE(empty, TestcaseBase)
{
  BOOST_TEST(result() == "");
  buf.write(nullptr, 0);
  BOOST_TEST(result() == "");
}

BOOST_FIXTURE_TEST_CASE(put, TestcaseBase)
{
  buf.put('a');
  buf.put('b');
  buf.put('c');
  BOOST_TEST(result() == "abc");
}

BOOST_FIXTURE_TEST_CASE(write, TestcaseBase)
{
  buf.write("defgh", 5);
  BOOST_TEST(result() == "defgh");
}

BOOST_FIXTURE_TEST_CASE(bool_true, TestcaseBase)
{
  buf << true;
  BOOST_TEST(result() == "true");
}

BOOST_FIXTURE_TEST_CASE(bool_false, TestcaseBase)
{
  buf << false;
  BOOST_TEST(result() == "false");
}

BOOST_AUTO_TEST_SUITE_END()

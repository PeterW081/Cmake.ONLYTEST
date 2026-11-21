#include <gtest/gtest.h>
#/*---*/
#include <regex>
#include <format>
#include <spdlog/fmt/std.h>
#include <spdlog/sinks/ostream_sink.h>
#/*---*/
#

namespace ns_test
{
	static constexpr auto regex = []() -> auto
	{
#if(not defined(SPDLOG_NO_SOURCE_LOC))
		return R"(\[[[:digit:]]{8}_[[:digit:]]{4}_[[:digit:]]{2}\.[[:digit:]]{3}\]\[ONLYTEST\]\[ )" __FILE_NAME__ R"(:[[:digit:]]+ \])";
#else
		return R"(\[[[:digit:]]{8}_[[:digit:]]{4}_[[:digit:]]{2}\.[[:digit:]]{3}\]\[ONLYTEST\])";
#endif
	}();

	static constexpr auto is_fmt_or_boost = []() -> auto //
	{
#if(false)
#	error
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
		return true;
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
		return false;
#elif(not defined(_MARCRO_ONLYTEST_0_ENABLE))
		return bool();
#else
#	error
#endif
	}();

	static auto FX_get_line(std::istream&) -> std::string;
}
auto ns_test::FX_get_line(std::istream& stream) -> std::string
{
	auto str = std::string();
	std::getline(stream, str);
	return str;
}

TEST(Assert02, test01_format)
{
#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
	GTEST_SKIP();
#endif

	auto strb = std::stringstream();
	ns_ONLYTEST::detail::FX_log_0_reset(std::make_shared<spdlog::sinks::ostream_sink_mt>(strb));
	{
		auto mark = "<MARK>";
		{
			auto regex = std::regex(std::format("{} ", ns_test::regex));
			SPDLOG_ONLYTEST();
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{} {} ", ns_test::regex, mark));
			SPDLOG_ONLYTEST_MARK(mark)();
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{}<TRACE> .*{}.*", ns_test::regex, __FUNCTION__));
			SPDLOG_ONLYTEST_TRACE();
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{}<TRACE> .*{}.* {}", ns_test::regex, __FUNCTION__, mark));
			SPDLOG_ONLYTEST_TRACE(mark);
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
	}
	ns_ONLYTEST::detail::FX_log_0_reset();
}

TEST(Assert02, test02_format)
{
#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
	GTEST_SKIP();
#endif

	auto strb = std::stringstream();
	ns_ONLYTEST::detail::FX_log_0_reset(std::make_shared<spdlog::sinks::ostream_sink_mt>(strb));
	{
		auto exception = std::runtime_error("what");
		auto func = [&exception]() -> int
		{
			throw std::runtime_error(exception);
		};
		{
			auto regex = std::regex(std::format("{}<CATCH> {}", ns_test::regex, fmt::format("{:t}", exception)));
			SPDLOG_ONLYTEST(func());
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
	}
	ns_ONLYTEST::detail::FX_log_0_reset();
}

TEST(Assert02, test03_format)
{
#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
	GTEST_SKIP();
#endif

	auto strb = std::stringstream();
	ns_ONLYTEST::detail::FX_log_0_reset(std::make_shared<spdlog::sinks::ostream_sink_mt>(strb));
	{
		auto& is_fmt_or_boost = ns_test::is_fmt_or_boost;
		auto mark = "<MARK>";
		auto text = "TEXT";
		{
			auto regex = std::regex(std::format("{} {}", ns_test::regex, ""));
			SPDLOG_ONLYTEST();
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{} {}", ns_test::regex, std::format("{}", text)));
			SPDLOG_ONLYTEST(text);
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{} {}", ns_test::regex, std::format("{},{},", text, text)));
			SPDLOG_ONLYTEST(is_fmt_or_boost ? "{},{}," : "%s,%s,", text, text);
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{} {} {}", ns_test::regex, mark, ""));
			SPDLOG_ONLYTEST_MARK(mark)();
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{} {} {}", ns_test::regex, mark, std::format("{}", text)));
			SPDLOG_ONLYTEST_MARK(mark)(text);
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
		{
			auto regex = std::regex(std::format("{} {} {}", ns_test::regex, mark, std::format("{},{},", text, text)));
			SPDLOG_ONLYTEST_MARK(mark)(is_fmt_or_boost ? "{},{}," : "%s,%s,", text, text);
			EXPECT_TRUE(std::regex_match(ns_test::FX_get_line(strb), regex)), strb = {};
		}
	}
	ns_ONLYTEST::detail::FX_log_0_reset();
}

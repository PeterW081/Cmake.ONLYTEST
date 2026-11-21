#include <gtest/gtest.h>
#/*---*/
#include <spdlog/sinks/null_sink.h>
#/*---*/
#

TEST(Assert01, test00)
{
	ns_ONLYTEST::detail::FX_log_0_reset(std::make_shared<spdlog::sinks::null_sink_mt>());
}

TEST(Assert01, test01_exception)
{
#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
	GTEST_SKIP();
#endif

	struct ExceptionInner : std::exception
	{
	};
	static constexpr auto func = []() -> std::string
	{
		throw ExceptionInner();
		return std::string();
	};

	{
		auto ptrException = std::exception_ptr();

		try
		{
			ptrException = {};
			SPDLOG_ONLYTEST(func());
		} catch(...)
		{
			ptrException = std::current_exception();
		}
		EXPECT_NO_THROW(if(ptrException != nullptr) { std::rethrow_exception(ptrException); });
	}

	{
		auto ptrException = std::exception_ptr();

		try
		{
			ptrException = {};
			SPDLOG_ONLYTEST_MARK("MARK")(func());
		} catch(...)
		{
			ptrException = std::current_exception();
		}
		EXPECT_THROW(if(ptrException != nullptr) { std::rethrow_exception(ptrException); }, ExceptionInner);

		try
		{
			ptrException = {};
			SPDLOG_ONLYTEST_MARK(func())("TEXT");
		} catch(...)
		{
			ptrException = std::current_exception();
		}
		EXPECT_THROW(if(ptrException != nullptr) { std::rethrow_exception(ptrException); }, ExceptionInner);

		try
		{
			ptrException = {};
			SPDLOG_ONLYTEST_TRACE(func());
		} catch(...)
		{
			ptrException = std::current_exception();
		}
		EXPECT_THROW(if(ptrException != nullptr) { std::rethrow_exception(ptrException); }, ExceptionInner);
	}
}

TEST(Assert01, test02_exception)
{
#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
	GTEST_SKIP();
#endif

	{
		auto ptrException = std::exception_ptr();

		try
		{
			ptrException = {};
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
			SPDLOG_ONLYTEST(fmt::runtime("{}{}"), "");
#endif
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
			SPDLOG_ONLYTEST("%||%||", "");
#endif
		} catch(...)
		{
			ptrException = std::current_exception();
		}
		EXPECT_NO_THROW(if(ptrException != nullptr) { std::rethrow_exception(ptrException); });

		try
		{
			ptrException = {};
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
			SPDLOG_ONLYTEST_MARK("MARK")(fmt::runtime("{}{}"), "");
#endif
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
			SPDLOG_ONLYTEST_MARK("MARK")("%||%||", "");
#endif
		} catch(...)
		{
			ptrException = std::current_exception();
		}
		EXPECT_NO_THROW(if(ptrException != nullptr) { std::rethrow_exception(ptrException); });
	}
}

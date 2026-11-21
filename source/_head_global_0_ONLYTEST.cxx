#include "_head_global_0_ONLYTEST.hxx"

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	/*---*/
#	include <thread>
#	include <map>
#	include <spdlog/fmt/std.h>
#	/*---*/
#

///
auto ns_ONLYTEST::detail::FX_sleep_second(std::uint64_t timev) -> void
{
	std::this_thread::sleep_for(std::chrono::seconds(timev));
}
auto ns_ONLYTEST::detail::FxMakeStr_this_thread_id() -> std::string
{
	static std::mutex mutex;
	static auto map = std::map<std::string, std::size_t>();
	auto thread_id = (std::stringstream() << std::this_thread::get_id()).str();
	if(map.find(thread_id) == map.end())
	{
		std::lock_guard<decltype(mutex)> lock(mutex);
		auto map_value = map.size();
		map[thread_id] = map_value + 1;
	}
	auto thread_mark = map[thread_id];
	return fmt::format("thread{:02d}-{}", thread_mark, thread_id);
}
auto ns_ONLYTEST::detail::FxMakeStr_this_exception(const std::exception_ptr& ptrException) -> std::string
{
	auto str = std::string();
	if(ptrException == nullptr)
	{
		str = "std::exception_ptr == nullptr";
	} else
	{
#	pragma ide diagnostic push
#	pragma ide diagnostic ignored "UnreachableCode"
		try
		{
			std::rethrow_exception(ptrException);
		} catch(const std::exception& e)
		{
			str = fmt::format("{:t}", e);
		} catch(const std::nullptr_t&)
		{
			str = fmt::format("std::exception_ptr: nullptr");
		} catch(const int& e)
		{
			str = fmt::format("std::exception_ptr: int({:d})", e);
		} catch(...)
		{
			static const auto fmt01_STRING = "std::exception_ptr: STRING: {:s}";
			static const auto fmt02_NUMBER = "std::exception_ptr: NUMBER: {:d}";
			static const auto fmt03_OTHERR = "std::exception_ptr: ...";
			try
			{
				throw;
			} catch(const std::string& e)
			{
				str = fmt::format(fmt01_STRING, e);
			} catch(const char& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const signed char& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const signed short& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const signed int& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const signed long& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const signed long long& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const unsigned char& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const unsigned short& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const unsigned int& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const unsigned long& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(const unsigned long long& e)
			{
				str = fmt::format(fmt02_NUMBER, e);
			} catch(...)
			{
				str = fmt::format(fmt03_OTHERR);
			}
		}
#	pragma ide diagnostic pop
	}
	return str;
}

#
#	/*---*/
#endif

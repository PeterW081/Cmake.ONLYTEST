#include "_head_global_0_ONLYTEST.hxx"

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	/*---*/
#	include <thread>
#	include <map>
#	/*---*/
#	include <spdlog/spdlog.h>
#	include <spdlog/sinks/stdout_sinks.h>
#	include <spdlog/pattern_formatter.h>
#	include <spdlog/pattern_formatter-inl.h>
#	/*---*/
#

///
namespace ns_ONLYTEST
{
	namespace detail
	{
		static auto FxFactory_logger() -> spdlog::logger;
		static spdlog::logger GV_logger = FxFactory_logger();
	}
}
auto ns_ONLYTEST::detail::FxFactory_logger() -> spdlog::logger
{
	const auto fmt_1_SPDLOG_NO_SOURCE_LOC = "[%Y%m%d_%H%M_%S.%e][ONLYTEST] %v";
	const auto fmt_0_SPDLOG_NO_SOURCE_LOC = "[%Y%m%d_%H%M_%S.%e][ONLYTEST][ %@ ] %v";

	auto logger = spdlog::logger("");
	logger.sinks().clear();
	logger.sinks().emplace_back(spdlog::details::make_unique<spdlog::sinks::stdout_sink_mt>());
#	if(defined(SPDLOG_NO_SOURCE_LOC))
	{
		logger.set_pattern(fmt_1_SPDLOG_NO_SOURCE_LOC);
	}
#	else
	{
		struct T01_custom_flag_formatter : public spdlog::custom_flag_formatter
		{
			auto format(spdlog::details::log_msg const& data, std::tm const&, spdlog::memory_buf_t& dest) -> void override
			{
				fmt::format_to(std::back_inserter(dest), "{:s}:{:04d}", spdlog::details::short_filename_formatter<spdlog::details::null_scoped_padder>::basename(data.source.filename), data.source.line);
			}
			auto clone() const -> std::unique_ptr<spdlog::custom_flag_formatter> override
			{
				return spdlog::details::make_unique<T01_custom_flag_formatter>(*this);
			}
		};
		auto pattern_formatter = spdlog::details::make_unique<spdlog::pattern_formatter>();
		pattern_formatter->add_flag<T01_custom_flag_formatter>('@');
		pattern_formatter->set_pattern(fmt_0_SPDLOG_NO_SOURCE_LOC);
		logger.set_formatter(std::move(pattern_formatter));
	}
#	endif
	logger.set_level(spdlog::level::debug);
	return logger;
}

///
auto ns_ONLYTEST::detail::FX_log(const char* file, int line, const std::string& msg) -> void
{
	ns_ONLYTEST::detail::GV_logger.log(spdlog::source_loc(file, line, ""), spdlog::level::debug, msg);
}
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

#
#	/*---*/
#endif

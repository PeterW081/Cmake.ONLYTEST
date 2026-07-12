#include "_head_global_0_ONLYTEST.hxx"
#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	pragma
#
#	include <thread>
#	include <map>
#	/*---*/
#	include <spdlog/spdlog.h>
#	include <spdlog/sinks/stdout_sinks.h>
#

///
namespace testonly
{
	namespace detail
	{
		static auto FxFactory_logger() -> spdlog::logger;
		static spdlog::logger GV_logger = FxFactory_logger();
	}
}
//X
auto testonly::detail::FxFactory_logger() -> spdlog::logger
{
	auto logger = spdlog::logger("");
	logger.sinks().clear();
	logger.sinks().emplace_back(spdlog::details::make_unique<spdlog::sinks::stdout_sink_mt>());
	logger.set_pattern("[%Y%m%d-%H%M-%S.%f] %v");
	logger.set_level(spdlog::level::debug);
	return logger;
}

///
auto testonly::detail::FX_log(const char* file, int line, const std::string& msg) -> void
{
	testonly::detail::GV_logger.log(spdlog::source_loc(file, line, ""), spdlog::level::debug, msg);
}
auto testonly::detail::FX_sleep_second(std::uint64_t timev) -> void
{
	std::this_thread::sleep_for(std::chrono::seconds(timev));
}
auto testonly::detail::FxMakeStr_this_thread_id() -> std::string
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
#	pragma
#endif

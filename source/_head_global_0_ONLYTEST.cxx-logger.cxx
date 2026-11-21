#include "_head_global_0_ONLYTEST.hxx"

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	/*---*/
#	include <spdlog/sinks/stdout_color_sinks.h>
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
		static auto FxFactory_formatter() -> std::unique_ptr<spdlog::pattern_formatter>;
		static spdlog::logger GV_logger = FxFactory_logger();
	}
}
auto ns_ONLYTEST::detail::FxFactory_logger() -> spdlog::logger
{
	auto logger = spdlog::logger("");
	auto sinker = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	{
		logger.sinks().clear();
		logger.sinks().emplace_back(sinker);
		logger.set_formatter(FxFactory_formatter());
	}
	{
		logger.set_level(spdlog::level::err);
	}
	return logger;
}
auto ns_ONLYTEST::detail::FxFactory_formatter() -> std::unique_ptr<spdlog::pattern_formatter>
{
	const auto fmt_1_SPDLOG_NO_SOURCE_LOC = "[%Y%m%d_%H%M_%S.%e][%^ONLYTEST%$]%v";
	const auto fmt_0_SPDLOG_NO_SOURCE_LOC = "[%Y%m%d_%H%M_%S.%e][%^ONLYTEST%$][ %@ ]%v";

	auto pattern_formatter = spdlog::details::make_unique<spdlog::pattern_formatter>();
#	if(defined(SPDLOG_NO_SOURCE_LOC))
	{
		pattern_formatter->set_pattern(fmt_1_SPDLOG_NO_SOURCE_LOC);
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
		pattern_formatter->add_flag<T01_custom_flag_formatter>('@');
		pattern_formatter->set_pattern(fmt_0_SPDLOG_NO_SOURCE_LOC);
	}
#	endif
	return pattern_formatter;
	static_assert(((void) fmt_1_SPDLOG_NO_SOURCE_LOC, (void) fmt_0_SPDLOG_NO_SOURCE_LOC, true), "");
}

///
auto ns_ONLYTEST::detail::FX_log(const char* file, int line, const std::function<auto()->std::string>& msg) -> void
{
	try
	{
		ns_ONLYTEST::detail::GV_logger.log(spdlog::source_loc(file, line, ""), spdlog::level::err, fmt::format(" {}", msg()));
	} catch(...)
	{
		ns_ONLYTEST::detail::GV_logger.log(spdlog::source_loc(file, line, ""), spdlog::level::err, fmt::format("<CATCH> {}", ns_ONLYTEST::detail::FxMakeStr_this_exception()));
	}
}
auto ns_ONLYTEST::detail::FX_log_trace(const char* file, int line, const std::string& func, const std::string& mark) -> void
{
	try
	{
		ns_ONLYTEST::detail::GV_logger.log(spdlog::source_loc(file, line, ""), spdlog::level::err, fmt::format("<TRACE> {} {}", func, mark));
	} catch(...)
	{
		ns_ONLYTEST::detail::GV_logger.log(spdlog::source_loc(file, line, ""), spdlog::level::err, fmt::format("<CATCH> {}", FxMakeStr_this_exception()));
	}
}
auto ns_ONLYTEST::detail::FX_log_0_reset(spdlog::sink_ptr sinker) -> void
{
	auto& logger = GV_logger;
	{
		if(sinker == nullptr)
		{
			sinker = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		}
		logger.sinks().clear();
		logger.sinks().emplace_back(sinker);
		logger.set_formatter(FxFactory_formatter());
	}
}

#
#	/*---*/
#endif

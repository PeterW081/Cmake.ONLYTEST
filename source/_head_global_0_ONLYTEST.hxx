#pragma once

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	/*---*/
#	include <exception>
#	include <thread>
#	include <string>
#	include <spdlog/fmt/fmt.h>
#	include <spdlog/sinks/sink.h>
#	/*---*/
#
namespace ns_ONLYTEST
{
	namespace detail_template
	{
		template<typename... TS_args>
		extern auto FX_format00_ez(TS_args&&...) -> std::string;
		template<typename... TS_fmt_args>
		extern auto FX_format01_fmt(typename fmt::format_string<TS_fmt_args...>::t, TS_fmt_args&&...) -> std::string;
		template<typename... TS_fmt_args>
		extern auto FX_format02_boost(const std::string&, TS_fmt_args&&...) -> std::string;
		extern auto FxMakeMsg() -> std::string;
		template<typename T_fmt_arg>
		extern auto FxMakeMsg(T_fmt_arg&&) -> std::string;
		template<typename... TS_fmt_args>
		extern auto FxMakeMsg(
#	if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
			typename fmt::format_string<TS_fmt_args...>::t,
#	else
			const std::string&,
#	endif
			TS_fmt_args&&...
		) -> std::string;
	}
	namespace detail
	{
		using namespace detail_template;
		extern auto FX_log(const char*, int, const std::function<auto()->std::string>&) -> void;         // file, line, msg,
		extern auto FX_log_trace(const char*, int, const std::string&, const std::string& = "") -> void; // file, line, func, mark,
		extern auto FX_log_0_reset(spdlog::sink_ptr = nullptr) -> void;
		extern auto FX_sleep_second(std::uint64_t) -> void;
		extern auto FxMakeStr_this_thread_id() -> std::string;
		extern auto FxMakeStr_this_exception(const std::exception_ptr& = std::current_exception()) -> std::string;
	}
	namespace detail_macro_helper
	{
		struct CallableForCxx11;
	}
}
struct ns_ONLYTEST::detail_macro_helper::CallableForCxx11
{
	const char* m_file;
	int m_line;
	std::string m_mark;
	explicit CallableForCxx11(const char*, int, std::string);
	auto operator()() const -> void;
	template<typename T_fmt_arg>
	auto operator()(T_fmt_arg&&) const -> void;
	template<typename... TS_fmt_args>
	auto operator()(
#	if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
		typename fmt::format_string<TS_fmt_args...>::t,
#	else
		const std::string&,
#	endif
		TS_fmt_args&&...
	) const -> void;
};
#
#	/*---*/
#	include "_head_global_0_ONLYTEST.hxx-MACRO-01.cc"
#	include "_head_global_0_ONLYTEST.hxx-MACRO-02.cc"
#	include "_head_global_0_ONLYTEST.txx"
#	/*---*/
#endif
#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
#	include "_head_global_0_ONLYTEST.hxx-MACRO-01.cc"
#	include "_head_global_0_ONLYTEST.hxx-MACRO-02.cc"
namespace ns_ONLYTEST
{
	namespace detail
	{
		template<typename... TS>
		extern auto FX_log_0_reset(TS&&...) -> void {};
	}
	namespace detail_macro_helper
	{
		template<typename... TS>
		extern auto FX_noop_for_cxx11(TS&&...) -> void {};
	}
}
#endif

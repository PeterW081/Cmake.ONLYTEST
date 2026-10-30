#pragma once

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	/*---*/
#	include <thread>
#	include <string>
#	include <spdlog/fmt/fmt.h>
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
	}
	namespace detail
	{
		using namespace detail_template;
		extern auto FX_log(const char*, int, const std::string&) -> void; // file, line, msg,
		extern auto FX_sleep_second(std::uint64_t) -> void;
		extern auto FxMakeStr_this_thread_id() -> std::string;
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
	explicit CallableForCxx11(const char*, int, const std::string&);
	template<typename T_arg1, typename... TS_args>
	auto operator()(T_arg1 arg1, TS_args&&... args) const -> void;
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
#endif

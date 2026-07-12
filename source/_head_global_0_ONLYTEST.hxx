#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	pragma once
#
#	include <thread>
#	include <string>
#	include <fmt/format.h>
#

namespace testonly
{
	namespace detail_template
	{
		template<typename... TS_args>
		extern auto FX_format00_ez(TS_args&&...) -> std::string;
		template<typename... TS_fmt_args>
		extern auto FX_format01_fmt(typename fmt::fstring<TS_fmt_args...>::t, TS_fmt_args&&...) -> std::string;
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
}

#
#	include "_head_global_0_ONLYTEST.txx"
#	include "_head_global_0_ONLYTEST.hxx-MACRO-01.cc"
#	include "_head_global_0_ONLYTEST.hxx-MACRO-02.cc"
#	pragma
#endif

#if(not defined(_MARCRO_ONLYTEST_0_ENABLE))
#	pragma once
#
#	include "_head_global_0_ONLYTEST.hxx-MACRO-01.cc"
#	include "_head_global_0_ONLYTEST.hxx-MACRO-02.cc"
#
#	pragma
#endif

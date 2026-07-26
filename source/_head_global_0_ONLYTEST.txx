#//include "_head_global_0_ONLYTEST.hxx"
#pragma
#
#include <sstream>
#include <fmt/format.h>
#include <boost/format.hpp>
#

///
template<typename... TS_args>
extern auto testonly::detail_template::FX_format00_ez(TS_args&&... args) -> std::string
{
	auto strb = std::stringstream();
	std::initializer_list<std::nullptr_t>{(strb << std::forward<TS_args>(args) << ", ", nullptr)...};
	return strb.str();
}
template<typename... TS_fmt_args>
extern auto testonly::detail_template::FX_format01_fmt(typename fmt::format_string<TS_fmt_args...>::t fmt, TS_fmt_args&&... fmt_args) -> std::string
{
	return fmt::format(fmt, std::forward<TS_fmt_args>(fmt_args)...);
}
template<typename... TS_fmt_args>
extern auto testonly::detail_template::FX_format02_boost(const std::string& fmt, TS_fmt_args&&... fmt_args) -> std::string
{
	auto itc_boost_format = boost::format(fmt);
	std::initializer_list<std::nullptr_t>{(itc_boost_format % fmt_args, nullptr)...};
	return itc_boost_format.str();
}

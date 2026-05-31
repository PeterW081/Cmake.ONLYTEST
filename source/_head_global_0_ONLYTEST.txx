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
	std::tie((strb << std::forward<TS_args>(args) << ", ")...);
	return strb.str();
}
template<typename... TS_fmt_args>
extern auto testonly::detail_template::FX_format01_fmt(typename fmt::fstring<TS_fmt_args...>::t fmt, TS_fmt_args&&... fmt_args) -> std::string
{
	return fmt::format(fmt, std::forward<TS_fmt_args>(fmt_args)...);
}
template<typename... TS_fmt_args>
extern auto testonly::detail_template::FX_format02_boost(const std::string& fmt, TS_fmt_args&&... fmt_args) -> std::string
{
	auto itc_boost_format = boost::format(fmt);
	std::tie(itc_boost_format % fmt_args...);
	return itc_boost_format.str();
}

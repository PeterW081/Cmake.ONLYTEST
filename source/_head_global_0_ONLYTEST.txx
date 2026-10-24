#//include "_head_global_0_ONLYTEST.hxx"
#/*---*/
#include <sstream>
#include <fmt/format.h>
#include <boost/format.hpp>
#/*---*/
#

///
template<typename... TS_args>
extern auto ns_ONLYTEST::detail_template::FX_format00_ez(TS_args&&... args) -> std::string
{
	auto strb = std::stringstream();
	std::initializer_list<std::nullptr_t>{(strb << std::forward<TS_args>(args) << ", ", nullptr)...};
	return strb.str();
}
template<typename... TS_fmt_args>
extern auto ns_ONLYTEST::detail_template::FX_format01_fmt(typename fmt::format_string<TS_fmt_args...>::t fmt, TS_fmt_args&&... fmt_args) -> std::string
{
	return fmt::format(fmt, std::forward<TS_fmt_args>(fmt_args)...);
}
template<typename... TS_fmt_args>
extern auto ns_ONLYTEST::detail_template::FX_format02_boost(const std::string& fmt, TS_fmt_args&&... fmt_args) -> std::string
{
	auto itc_boost_format = boost::format(fmt);
	std::initializer_list<std::nullptr_t>{(itc_boost_format % fmt_args, nullptr)...};
	return itc_boost_format.str();
}

///
inline ns_ONLYTEST::detail_macro_helper::CallableForCxx11::CallableForCxx11(const char* file, int line, const std::string& mark)
	: m_file(file)
	, m_line(line)
	, m_mark(mark)
{
}
template<typename T_arg1, typename... TS_args>
inline auto ns_ONLYTEST::detail_macro_helper::CallableForCxx11::operator()(T_arg1 arg1, TS_args&&... args) const -> void
{
#if(false)
#elif(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT)
	auto arg1_ = fmt::runtime(arg1);
#elif(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST)
	auto& arg1_ = arg1;
#endif
	ns_ONLYTEST::detail::FX_log(m_file, m_line, m_mark + ns_ONLYTEST::detail::_MARCRO_ONLYTEST_0_FORMAT_FUNCTION(arg1_, args...));
}

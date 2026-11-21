#//include "_head_global_0_ONLYTEST.hxx"
#/*---*/
#include <sstream>
#include <boost/format.hpp>
#include <spdlog/fmt/fmt.h>
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
inline auto ns_ONLYTEST::detail_template::FxMakeMsg() -> std::string
{
	return "";
}
template<typename T_fmt_arg>
extern auto ns_ONLYTEST::detail_template::FxMakeMsg(T_fmt_arg&& arg1) -> std::string
{
#if(false)
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
	return ns_ONLYTEST::detail_template::FX_format01_fmt("{}", std::forward<T_fmt_arg>(arg1));
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
	return ns_ONLYTEST::detail_template::FX_format02_boost("%||", std::forward<T_fmt_arg>(arg1));
#else
	return {};
#	error
#endif
}
template<typename... TS_fmt_args>
extern auto ns_ONLYTEST::detail_template::FxMakeMsg(
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
	typename fmt::format_string<TS_fmt_args...>::t arg1,
#else
	const std::string& arg1,
#endif
	TS_fmt_args&&... args
) -> std::string
{
#if(false)
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
	return ns_ONLYTEST::detail_template::FX_format01_fmt(arg1, std::forward<TS_fmt_args>(args)...);
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
	return ns_ONLYTEST::detail_template::FX_format02_boost(arg1, std::forward<TS_fmt_args>(args)...);
#else
	return {};
#	error
#endif
}

///
inline ns_ONLYTEST::detail_macro_helper::CallableForCxx11::CallableForCxx11(const char* file, int line, std::string mark)
	: m_file(file)
	, m_line(line)
	, m_mark(std::move(mark))
{
}
inline auto ns_ONLYTEST::detail_macro_helper::CallableForCxx11::operator()() const -> void
{
	const auto msg = [&]() -> std::string
	{
		return fmt::format("{} ", this->m_mark);
	};
	ns_ONLYTEST::detail::FX_log(m_file, m_line, msg);
}
template<typename T_fmt_arg>
inline auto ns_ONLYTEST::detail_macro_helper::CallableForCxx11::operator()(T_fmt_arg&& arg1) const -> void
{
	const auto msg = [this, &arg1]() -> std::string
	{
		return fmt::format("{} {}", this->m_mark, ns_ONLYTEST::detail_template::FxMakeMsg(std::forward<T_fmt_arg>(arg1)));
	};
	ns_ONLYTEST::detail::FX_log(m_file, m_line, msg);
}
template<typename... TS_fmt_args>
inline auto ns_ONLYTEST::detail_macro_helper::CallableForCxx11::operator()(
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
	typename fmt::format_string<TS_fmt_args...>::t arg1,
#else
	const std::string& arg1,
#endif
	TS_fmt_args&&... args
) const -> void
{
	const auto msg = [this, &arg1, &args...]() -> std::string
	{
		return fmt::format("{} {}", m_mark, ns_ONLYTEST::detail_template::FxMakeMsg(arg1, std::forward<TS_fmt_args>(args)...));
	};
	ns_ONLYTEST::detail::FX_log(m_file, m_line, msg);
}

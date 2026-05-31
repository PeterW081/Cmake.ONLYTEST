#//include "_head_global_0_ONLYTEST.hxx"
#pragma
#

#/**/
#undef _MARCRO_ONLYTEST_0_FORMAT_FUNCTION
#if(false)
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
#	define _MARCRO_ONLYTEST_0_FORMAT_FUNCTION FX_format01_fmt
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
#	define _MARCRO_ONLYTEST_0_FORMAT_FUNCTION FX_format02_boost
#endif
#

#/**/
#if(not defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT) and not defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
#	define SPDLOG_ONLYTEST(...)
#	define SPDLOG_ONLYTEST_MARK(MACRO_P1) [](...) -> void {}
#else
#	define SPDLOG_ONLYTEST(...)           testonly::detail::FX_log(__FILE__, __LINE__, testonly::detail::_MARCRO_ONLYTEST_0_FORMAT_FUNCTION(__VA_ARGS__))
#	define SPDLOG_ONLYTEST_MARK(MACRO_P1) testonly::detail_macro_helper::CallableForCxx11(__FILE__, __LINE__, "[" MACRO_P1 "] ")
#endif
#

namespace testonly
{
	namespace detail_macro_helper
	{
		struct CallableForCxx11;
	}
}

struct testonly::detail_macro_helper::CallableForCxx11
{
	const char* m_file;
	int m_line;
	std::string m_mark;
	explicit CallableForCxx11(const char*, int, std::string);
	template<typename T_arg1, typename... TS_args>
	auto operator()(T_arg1 arg1, TS_args&&... args) const -> void;
};

inline testonly::detail_macro_helper::CallableForCxx11::CallableForCxx11(const char* file, int line, std::string mark)
	: m_file(file)
	, m_line(line)
	, m_mark(mark)
{
}
template<typename T_arg1, typename... TS_args>
inline auto testonly::detail_macro_helper::CallableForCxx11::operator()(T_arg1 arg1, TS_args&&... args) const -> void
{
#if(false)
#elif(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT)
	auto arg1_ = fmt::runtime(arg1);
#elif(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST)
	auto& arg1_ = arg1;
#endif
#if(defined(_MARCRO_ONLYTEST_0_FORMAT_FUNCTION))
	testonly::detail::FX_log(m_file, m_line, m_mark + testonly::detail::_MARCRO_ONLYTEST_0_FORMAT_FUNCTION(arg1_, args...));
#endif
}

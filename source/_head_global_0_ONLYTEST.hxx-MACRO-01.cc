#//include "_head_global_0_ONLYTEST.hxx"
#/*---*/
#

#undef _MARCRO_ONLYTEST_0_FORMAT_FUNCTION
#if(false)
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT))
#	define _MARCRO_ONLYTEST_0_FORMAT_FUNCTION FX_format01_fmt
#elif(defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
#	define _MARCRO_ONLYTEST_0_FORMAT_FUNCTION FX_format02_boost
#else
#endif

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	define SPDLOG_ONLYTEST(...)           ns_ONLYTEST::detail::FX_log(__FILE__, __LINE__, ns_ONLYTEST::detail::_MARCRO_ONLYTEST_0_FORMAT_FUNCTION(__VA_ARGS__))
#	define SPDLOG_ONLYTEST_MARK(MACRO_P1) ns_ONLYTEST::detail_macro_helper::CallableForCxx11(__FILE__, __LINE__, MACRO_P1)
#else
#	define SPDLOG_ONLYTEST(...)
#	define SPDLOG_ONLYTEST_MARK(MACRO_P1) [](...) -> void {}
#endif

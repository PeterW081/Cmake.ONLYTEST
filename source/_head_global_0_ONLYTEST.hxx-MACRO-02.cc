#//include "_head_global_0_ONLYTEST.hxx"
#/*---*/
#

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	define STD_SLEEP_SECOND_ONLYTEST(MACRO_P1) ns_ONLYTEST::detail::FX_sleep_second(MACRO_P1)
#	define STRING_ONLYTEST(...)                ns_ONLYTEST::detail::FX_format00_ez(__VA_ARGS__)
#	define STRING_ONLYTEST_THIS_THREAD_ID()    ns_ONLYTEST::detail::FxMakeStr_this_thread_id()
#	define STRING_ONLYTEST_THIS_FUNCTION()     std::string(__FUNCTION__)
#	define STRING_ONLYTEST_THIS_EXCEPTION(...) ns_ONLYTEST::detail::FxMakeStr_this_exception(__VA_ARGS__)
#else
#	define STD_SLEEP_SECOND_ONLYTEST(MACRO_P1)
#	define STRING_ONLYTEST(...)             std::string()
#	define STRING_ONLYTEST_THIS_THREAD_ID() std::string()
#	define STRING_ONLYTEST_THIS_FUNCTION()  std::string()
#	define STRING_ONLYTEST_THIS_EXCEPTION() std::string()
#endif

#if(defined(_MARCRO_ONLYTEST_0_ENABLE) && (defined(__clang__) || defined(__GNUC__)) /**/)
#	if(not defined(STRING_ONLYTEST_THIS_FUNCTION))
#		error
#	endif
#	undef STRING_ONLYTEST_THIS_FUNCTION
#	define STRING_ONLYTEST_THIS_FUNCTION() std::string(__PRETTY_FUNCTION__)
#endif

#//include "_head_global_0_ONLYTEST.hxx"
#pragma
#

#/**/
#if(not defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT) and not defined(_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST))
#	define STD_SLEEP_SECOND_ONLYTEST(MACRO_P1)
#	define STRING_ONLYTEST(...)             std::string()
#	define STRING_ONLYTEST_THIS_THREAD_ID() std::string()
#else
#	define STD_SLEEP_SECOND_ONLYTEST(MACRO_P1) testonly::detail::FX_sleep_second(MACRO_P1)
#	define STRING_ONLYTEST(...)                testonly::detail::FX_format00_ez(__VA_ARGS__)
#	define STRING_ONLYTEST_THIS_THREAD_ID()    testonly::detail::FxMakeStr_this_thread_id()
#endif
#

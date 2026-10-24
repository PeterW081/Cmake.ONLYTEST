#//include "_head_global_0_ONLYTEST.hxx"
#/*---*/
#

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	define STD_SLEEP_SECOND_ONLYTEST(MACRO_P1) ns_ONLYTEST::detail::FX_sleep_second(MACRO_P1)
#	define STRING_ONLYTEST(...)                ns_ONLYTEST::detail::FX_format00_ez(__VA_ARGS__)
#	define STRING_ONLYTEST_THIS_THREAD_ID()    ns_ONLYTEST::detail::FxMakeStr_this_thread_id()
#else
#	define STD_SLEEP_SECOND_ONLYTEST(MACRO_P1)
#	define STRING_ONLYTEST(...)             std::string()
#	define STRING_ONLYTEST_THIS_THREAD_ID() std::string()
#endif

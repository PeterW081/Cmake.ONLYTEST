#//include "_head_global_0_ONLYTEST.hxx"
#/*---*/
#

#if(defined(_MARCRO_ONLYTEST_0_ENABLE))
#	define SPDLOG_ONLYTEST(...)                                                                                \
		ns_ONLYTEST::detail::FX_log(                                                                            \
			__FILE__, __LINE__,                                                                                 \
			[&]() -> std::string                                                                                \
			{                                                                                                   \
				return ns_ONLYTEST::detail_template::FxMakeMsg(__VA_ARGS__ /*NOLINT(*-lambda-function-name)*/); \
			}                                                                                                   \
		)
#	define SPDLOG_ONLYTEST_MARK(MACRO_P1) ns_ONLYTEST::detail_macro_helper::CallableForCxx11(__FILE__, __LINE__, MACRO_P1)
#	define SPDLOG_ONLYTEST_TRACE(...)     ns_ONLYTEST::detail::FX_log_trace(__FILE__, __LINE__, STRING_ONLYTEST_THIS_FUNCTION(), ##__VA_ARGS__)
#else
#	define SPDLOG_ONLYTEST(...)
#	define SPDLOG_ONLYTEST_MARK(MACRO_P1) ns_ONLYTEST::detail_macro_helper::FX_noop_for_cxx11
#	define SPDLOG_ONLYTEST_TRACE(...)
#endif

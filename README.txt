#! yq

- execute: "bash"
  content: |
    cd "${dir_cmake_project:?}";
    mkdir ./_package/
    touch ./_package/_include.cmake

- execute: "vim ./_package/_include.cmake"
  feature: [ FileCreate, ]
  content: |
    if(ON)
      ### - ONLYTEST
      # FetchContent_Declare()
      # > wget "https://github.com/PeterW081/Cmake.ONLYTEST/archive/refs/tags/340.115.436.2.zip" -O ./cmake_fetch_content-ONLYTEST.zip
      ###
      option(OPT_ONLYTEST_CLEANUP "" OFF)
      if(OPT_ONLYTEST_CLEANUP OR CMAKE_BUILD_TYPE STREQUAL Release)
        message(DEPRECATION)
      endif()
      option(OPT_ONLYTEST_ENABLE "" ON)
      option(OPT_ONLYTEST_FORMAT_0_IS_FMT_OR_BOOST "" ON)
      option(OPT_ONLYTEST_FIND_PACKAGE_FORCE_0_SPDLOG "" ON)
      ###
      include(FetchContent)
      FetchContent_Declare(
        FetchContent_ONLYTEST
        URL "${CMAKE_CURRENT_LIST_DIR}/cmake_fetch_content-ONLYTEST.zip"
        URL_MD5 "00000000000000000000000000000000"
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
      )
      FetchContent_MakeAvailable(FetchContent_ONLYTEST)
    endif()

- execute: "vim CMakeLists.txt"
  feature: [ CmakeExample, FileModify, ]
  content: |
    if(NOT CMAKE_BUILD_TYPE STREQUAL Release)
      include("${CMAKE_SOURCE_DIR}/_package/_include.cmake")
      link_libraries(
        ONLYTEST
      )
    endif()

- execute: "vim source.cxx"
  feature: [ CxxExample, ]
  content: |
    int main(int, char**)
    {
    	{
    		SPDLOG_ONLYTEST("{}", "info");
    		SPDLOG_ONLYTEST_MARK("<mark> ")("{}", "info");
    	}
    	{
    		STD_SLEEP_SECOND_ONLYTEST(1);
    		std::string() = STRING_ONLYTEST_THIS_THREAD_ID();
    		std::string() = STRING_ONLYTEST(int(), char('c'), std::string("str"));
    	}
    }

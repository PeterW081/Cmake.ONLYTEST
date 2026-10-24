#! yq

- execute: "bash"
  content: |
    cd "${dir_cmake_project:?}";
    mkdir ./_package/
    touch ./_package/_include.cmake

- execute: "vim ./_package/_include.cmake"
  feature: [ FileModify, ]
  content: |
    include("${CMAKE_SOURCE_DIR}/_package/_include.cmake")

- execute: "vim ./_package/_include.cmake"
  feature: [ FileCreate, ]
  content: |
    if(ON)
      ### - ONLYTEST
      # FetchContent_Declare()
      # > wget "https://github.com/PeterW081/Cmake.ONLYTEST/archive/refs/tags/340.115.436.1.zip" -O ./cmake_fetch_content-spdlog.zip
      ###
      option(OPT_ONLYTEST_ENABLE "" OFF)
      option(OPT_ONLYTEST_FORMAT_0_IS_FMT_OR_BOOST "" ON)
      ###
      include(FetchContent)
      FetchContent_Declare(
        FetchContent_ONLYTEST
        URL "${CMAKE_CURRENT_LIST_DIR}/cmake_fetch_content-ONLYTEST.tar"
        URL_MD5 "f9f3173ef71d0e4e51c635bebfaac26b"
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
      )
      FetchContent_MakeAvailable(FetchContent_ONLYTEST)
    endif()

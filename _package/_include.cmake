
###
add_library(ONLYTEST_0_deps INTERFACE)

### - Boost
find_package("Boost" CONFIG COMPONENTS)
find_package("Boost" CONFIG COMPONENTS "headers")
if(TARGET "Boost::boost")
  target_link_libraries(
    ONLYTEST_0_deps INTERFACE "Boost::boost"
  )
endif()
if(TARGET "Boost::headers")
  target_link_libraries(
    ONLYTEST_0_deps INTERFACE "Boost::headers"
  )
endif()
if((NOT TARGET "Boost::boost") AND (NOT TARGET "Boost::boost"))
  message(FATAL_ERROR)
endif()

### - Spdlog
# FetchContent_Declare()
# > wget "https://github.com/gabime/spdlog/archive/refs/tags/v1.15.3.zip" -O ./cmake_fetch_content-spdlog.zip
###
include(FetchContent)
set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  FetchContent_spdlog
  URL "${CMAKE_CURRENT_LIST_DIR}/cmake_fetch_content-spdlog.zip"
  URL_MD5 "F00DFA11FD9EE2F9B54D0315F4590E6B"
  DOWNLOAD_EXTRACT_TIMESTAMP OFF
)
FetchContent_MakeAvailable(FetchContent_spdlog)
target_link_libraries(
  ONLYTEST_0_deps INTERFACE "spdlog::spdlog"
)

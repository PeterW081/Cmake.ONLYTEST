
###
add_library(ONLYTEST_0_deps INTERFACE)

### - Boost
if(NOT OPT_ONLYTEST_CLEANUP)
  ###
  # find_package()
  # > brew install boost
  # > sudo dnf install boost-devel
  # > sudo apt install libboost-all-dev
  ###
  if(POLICY CMP0167)
    cmake_policy(SET CMP0167 OLD)
  endif()
  find_package("Boost" CONFIG COMPONENTS)
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
  if((NOT TARGET "Boost::boost") AND (NOT TARGET "Boost::headers"))
    message(FATAL_ERROR)
  endif()
endif()

### - Spdlog
if(NOT OPT_ONLYTEST_CLEANUP)
  ###
  # find_package()
  # > brew install spdlog
  # > sudo dnf install spdlog-devel
  # > sudo apt install libspdlog-dev
  # FetchContent_Declare()
  # > wget "https://github.com/gabime/spdlog/archive/refs/tags/v1.15.3.zip" -O ./cmake_fetch_content-spdlog.zip
  ###
  if(ON)
    find_package("spdlog")
    find_package("fmt")
  endif()
  if((NOT TARGET spdlog::spdlog) AND (NOT OPT_ONLYTEST_FIND_PACKAGE_FORCE_0_SPDLOG))
    if(POLICY CMP0135)
      cmake_policy(SET CMP0135 NEW)
    endif()
    include(FetchContent)
    set(SPDLOG_FMT_EXTERNAL OFF CACHE BOOL "" FORCE)
    FetchContent_Declare(
      FetchContent_spdlog
      URL "${CMAKE_CURRENT_LIST_DIR}/cmake_fetch_content-spdlog.zip"
      URL_MD5 "F00DFA11FD9EE2F9B54D0315F4590E6B"
    )
    FetchContent_MakeAvailable(FetchContent_spdlog)
  else()
    if(TARGET "fmt::fmt")
      target_link_libraries(
        "spdlog::spdlog" INTERFACE "fmt::fmt"
      )
    endif()
  endif()
  target_link_libraries(
    ONLYTEST_0_deps INTERFACE "spdlog::spdlog"
  )
endif()

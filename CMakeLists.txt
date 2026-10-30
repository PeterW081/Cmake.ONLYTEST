set(VAR_cmake_minimum_required "3.12")
set(VAR_project_name "ONLYTEST")
set(VAR_project_edit "340.115.436.2")
##X
option(OPT_ONLYTEST_CLEANUP "" OFF)
option(OPT_ONLYTEST_DISABLE_FORCE "" OFF)
option(OPT_ONLYTEST_ENABLE "" ON)
option(OPT_ONLYTEST_FORMAT_0_IS_FMT_OR_BOOST "" ON)
option(OPT_ONLYTEST_FIND_PACKAGE_FORCE_0_SPDLOG "" ON)

###
cmake_minimum_required(VERSION "${VAR_cmake_minimum_required}")
project("${VAR_project_name}" VERSION "${VAR_project_edit}")
include("${PROJECT_SOURCE_DIR}/_package/_include.cmake")

###
if(OPT_ONLYTEST_CLEANUP)
  add_library("${VAR_project_name}" INTERFACE)
else()
  add_library("${VAR_project_name}" STATIC)
  ##X
  file(GLOB_RECURSE ARR_cxx_source "${PROJECT_SOURCE_DIR}/source/*.cxx")
  list(APPEND ARR_cxx_header "${PROJECT_SOURCE_DIR}/source/")
  target_sources(
    "${VAR_project_name}" PRIVATE "${ARR_cxx_source}"
  )
  target_include_directories(
    "${VAR_project_name}" PRIVATE "${ARR_cxx_header}"
  )
  ##X
  target_link_libraries(
    "${VAR_project_name}" PUBLIC ONLYTEST_0_deps
  )
  ##X
  target_precompile_headers(
    "${VAR_project_name}" PUBLIC "${PROJECT_SOURCE_DIR}/source/_head_global_0_ONLYTEST.hxx"
  )
  if(NOT OPT_ONLYTEST_DISABLE_FORCE AND OPT_ONLYTEST_ENABLE)
    target_compile_definitions(
      "${VAR_project_name}" PUBLIC "_MARCRO_ONLYTEST_0_ENABLE"
    )
    if(OPT_ONLYTEST_FORMAT_0_IS_FMT_OR_BOOST)
      target_compile_definitions(
        "${VAR_project_name}" PUBLIC "_MARCRO_ONLYTEST_0_FORMAT_WITH_FMT"
      )
    else()
      target_compile_definitions(
        "${VAR_project_name}" PUBLIC "_MARCRO_ONLYTEST_0_FORMAT_WITH_BOOST"
      )
    endif()
  endif()
endif()

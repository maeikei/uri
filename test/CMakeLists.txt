# Copyright (c) Glyn Matthews 2012.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)


include_directories(${GTEST_INCLUDE_DIRS})

set(
  TESTS
  uri_test
  uri_encoding_test
  uri_normalization_test
  uri_comparison_test
  uri_relativize_test
  uri_resolve_test
  uri_builder_test
  )
if(CPP-NETLIB_BUILD_SINGLE_LIB)
  set(link_cppnetlib_lib cppnetlib)
  set(dependencies cppnetlib)
else()
  set(link_cppnetlib_lib cppnetlib-uri)
  set(dependencies cppnetlib-uri)
endif()
foreach (test ${TESTS})
  add_executable(${test} ${test}.cpp)
  add_dependencies(${test} ${dependencies})
  target_link_libraries(${test} ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${link_cppnetlib_lib})
  if (OPENSSL_FOUND)
    target_link_libraries(${test} ${OPENSSL_LIBRARIES})
  endif()
  set_target_properties(${test}
    PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${Uri_BINARY_DIR}/tests)
  add_test(${test}
    ${Uri_BINARY_DIR}/tests/${test})
endforeach (test)

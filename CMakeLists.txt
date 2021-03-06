# Copyright (c) Glyn Matthews 2012.
# Distributed under the Boost Software License, Version 1.0.
# (See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)


cmake_minimum_required(VERSION 2.8)
project(Uri)

option( CPP-NETLIB_BUILD_TESTS "Build the unit tests." OFF )

find_package(Threads REQUIRED)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.53 REQUIRED)

include_directories(${Uri_SOURCE_DIR}/src ${Boost_INCLUDE_DIRS})

set(CMAKE_VERBOSE_MAKEFILE true)

if (${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
  INCLUDE(CheckCXXCompilerFlag)
  CHECK_CXX_COMPILER_FLAG(-std=c++11 HAVE_STD11)

  if (HAVE_STD11)
    set(CMAKE_CXX_FLAGS -std=c++11)
  else()
    message(FATAL_ERROR "No C++ 11 support (Compiler does not define -std=c++11).")
  endif()
  message("C++ Flags: ${CMAKE_CXX_FLAGS} link flags: ${CMAKE_CXX_LINK_FLAGS}")
elseif(${CMAKE_CXX_COMPILER_ID} MATCHES Clang)
  if (CPP-NETLIB_DISABLE_LIBCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11")
    set(CMAKE_CXX_LINK_FLAGS "-std=c++11")
  else()
    set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++")
    set(CMAKE_CXX_LINK_FLAGS "-std=c++11 -stdlib=libc++")
  endif()
  message("C++ Flags: ${CMAKE_CXX_FLAGS} link flags: ${CMAKE_CXX_LINK_FLAGS}")
endif()


if (MSVC)
  add_definitions(-D_SCL_SECURE_NO_WARNINGS -D_VARIADIC_MAX=10)
endif(MSVC)
if (WIN32)
  add_definitions(-D_WIN32_WINNT=0x0501)
endif(WIN32)

add_subdirectory(src)

#propagate sources to parent scope for one-lib-build
set(Uri_SRCS ${Uri_SRCS} PARENT_SCOPE)

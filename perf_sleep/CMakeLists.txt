cmake_minimum_required(VERSION 3.5)

project(perf_sleep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type" FORCE)
endif()

if (DEFINED ENV{CONDA_PREFIX})
    set(CMAKE_INSTALL_PREFIX $ENV{CONDA_PREFIX} CACHE PATH "Install prefix" FORCE)
endif()

# set(CMAKE_INSTALL_PREFIX "${PREFIX}" CACHE PATH "Installation prefix" FORCE)

# Locate Python and its libraries
find_package(pybind11 REQUIRED)

set(LIBRARY_TARGET_NAME perf_sleep) # set library name

add_library(${LIBRARY_TARGET_NAME} SHARED
  src/perf_sleep.cpp
)

include_directories(
    include/
    src/
)

execute_process(
      COMMAND "${PYTHON_EXECUTABLE}" -c "if True:
        from distutils import sysconfig as sc
        print(sc.get_python_lib(prefix='', plat_specific=True))"
      OUTPUT_VARIABLE PYTHON_SITE
      OUTPUT_STRIP_TRAILING_WHITESPACE)

install(TARGETS ${LIBRARY_TARGET_NAME}
      DESTINATION ${CMAKE_INSTALL_PREFIX}/${PYTHON_SITE}/${PROJECT_NAME})

add_subdirectory(pybindings/)
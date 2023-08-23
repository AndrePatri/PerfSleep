cmake_minimum_required(VERSION 3.5)
find_package(pybind11 REQUIRED)
add_compile_options(-std=c++14)

message(STATUS "compiling python bindings")

execute_process(
      COMMAND "${PYTHON_EXECUTABLE}" -c "if True:
        from distutils import sysconfig as sc
        print(sc.get_python_lib(prefix='', plat_specific=True))"
      OUTPUT_VARIABLE PYTHON_SITE
      OUTPUT_STRIP_TRAILING_WHITESPACE)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
pybind11_add_module(pyperfsleep py_perf_sleep.cpp)
target_link_libraries(pyperfsleep PUBLIC perf_sleep)

install(TARGETS pyperfsleep
            DESTINATION ${CMAKE_INSTALL_PREFIX}/${PYTHON_SITE}/${PROJECT_NAME})

install(FILES __init__.py DESTINATION ${CMAKE_INSTALL_PREFIX}/${PYTHON_SITE}/${PROJECT_NAME})

# install(TARGETS  DESTINATION "${PREFIX}/")

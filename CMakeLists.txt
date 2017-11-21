cmake_minimum_required (VERSION 2.8.7)
project (text-wall-gen)

MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR} )

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

# add some imagemagik flags
SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16")

SET (project_source_files
  src/main.cpp
  )

add_executable (text-wall-gen ${project_source_files})

find_library(
	YAMLCPP_LIBRARY
	NAMES yaml-cpp
	DOC "The yaml-cpp library")

find_package (ImageMagick COMPONENTS Magick++)

include_directories ("src" ${ImageMagick_INCLUDE_DIRS})
target_link_libraries (text-wall-gen ${ImageMagick_LIBRARIES} ${YAMLCPP_LIBRARY})

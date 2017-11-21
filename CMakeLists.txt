cmake_minimum_required (VERSION 2.8.7)
project (text-wall-gen)

MESSAGE( STATUS "CMAKE_BINARY_DIR:         " ${CMAKE_BINARY_DIR} )

SET (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16")

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

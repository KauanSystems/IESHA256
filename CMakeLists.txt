cmake_minimum_required(VERSION 3.10)
project(IESHA256)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
	"${CMAKE_SOURCE_DIR}/external/sha"
	
	"${CMAKE_SOURCE_DIR}/include"
	"${CMAKE_SOURCE_DIR}/include/core"
	
	"${CMAKE_SOURCE_DIR}/src"
	"${CMAKE_SOURCE_DIR}/src/core"
)

file(
	GLOB_RECURSE Sources "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

set(SHA_DIR "${CMAKE_SOURCE_DIR}/external/sha/")

file(GLOB SHA_SOURCES 
    "${SHA_DIR}/*.cpp" 
    "${SHA_DIR}/*.h"
)

set(EXTERNAL_SOURCES
    ${SHA_SOURCES}
)

add_executable(
	${PROJECT_NAME}
	${Sources}
	${EXTERNAL_SOURCES}
)

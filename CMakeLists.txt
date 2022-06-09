# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (util_tools C CXX)

set(CMAKE_CXX_STANDARD 20)

if (LOG_ON)
	add_compile_definitions("LOG_ON")
endif ()

include_directories(".")

# includes set up

if ("${DEPS}" STREQUAL "")
	message("util_tools: WARNING: DEPS is not specified. Take the default value")
	set(DEPS "${PROJECT_SOURCE_DIR}/dependencies")
else()
	message("util_tools: DEPS: ${DEPS}")
endif()

set(UTILS_DIR "${DEPS}/Utils/include")
foreach(items ${UTILS_DIR})
	file(GLOB_RECURSE UTILS_SRC "${items}/*.cpp")
endforeach()
set(CUSTOM_INCLUDES ${UTILS_DIR})

set(util_tools_INCLUDES "${PROJECT_SOURCE_DIR}/include")

if (NOT "${CUSTOM_INCLUDES}" STREQUAL "")
	set(util_tools_INCLUDES ${util_tools_INCLUDES} ${CUSTOM_INCLUDES})
endif()


set(PARENT_SRC ${UTILS_SRC})
set(PARENT_SRC ${PARENT_SRC} PARENT_SCOPE)

if (NOT "${INCLUDES}" STREQUAL "")
	message("util_tools: External INCLUDES variable: ${INCLUDES}")
	set(util_tools_INCLUDES ${util_tools_INCLUDES} ${INCLUDES})
	foreach(items ${INCLUDES})
		file(GLOB_RECURSE INCLUDES_SRC "${items}/*.cpp")
	endforeach()
	message("util_tools: External INCLUDES sources: ${INCLUDES_SRC}")
endif()

set(util_tools_INCLUDES ${util_tools_INCLUDES} PARENT_SCOPE)
message("util_tools: util_tools_INCLUDES: ${util_tools_INCLUDES}")

include_directories("${util_tools_INCLUDES}")

# end of includes set up

add_subdirectory ("numbers_transform")
add_subdirectory ("numbers_average")

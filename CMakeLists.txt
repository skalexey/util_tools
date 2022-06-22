# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (util_tools C CXX)

set(CMAKE_CXX_STANDARD 20)

option(INHERIT_PARENT_SRC "Adds all parent's source files" OFF)
option(INHERIT_PARENT_LIBS "Adds all parent's libraries" OFF)

message("util_tools: INHERIT_PARENT_SRC is ${INHERIT_PARENT_SRC}")
message("util_tools: INHERIT_PARENT_LIBS is ${INHERIT_PARENT_LIBS}")

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

set(util_tools_INCLUDES "${PROJECT_SOURCE_DIR}/include")

if (NOT "${CUSTOM_INCLUDES}" STREQUAL "")
	set(util_tools_INCLUDES ${util_tools_INCLUDES} ${CUSTOM_INCLUDES})
endif()

# Inherit parent sources logic
set(PARENT_SRC ${PARENT_SRC} ${SRC})
set(PARENT_SRC ${PARENT_SRC} PARENT_SCOPE)

if (INHERIT_PARENT_SRC)
	set(SRC ${PARENT_SRC})
	message("util_tools: PARENT_SRC: ${PARENT_SRC}")
endif()
# End of Inherit parent sources logic

# Inherit parent libs logic
set(PARENT_LIBS ${PARENT_LIBS} ${LIBS})
set(PARENT_LIBS ${PARENT_LIBS} PARENT_SCOPE)

if (util_tools_INHERIT_PARENT_LIBS)
	set(LIBS ${PARENT_LIBS})
	message("util_tools: PARENT_LIBS: ${PARENT_LIBS}")
endif()
# End of Inherit parent libs logic

# Include Utils library (example)
set(UTILS_DIR "${DEPS}/Utils")
add_subdirectory ("${UTILS_DIR}" "${UTILS_DIR}/Build-cmake")

set(CUSTOM_INCLUDES ${CUSTOM_INCLUDES} ${utils_INCLUDES})

# Add the lib to PARENT_LIBS for including in subprojects (example)
set(PARENT_LIBS ${PARENT_LIBS} utils "${UTILS_DIR}" "${UTILS_DIR}/Build-cmake")
set(PARENT_LIBS ${PARENT_LIBS} PARENT_SCOPE)

if (NOT "${INCLUDES}" STREQUAL "")
	message("util_tools: External INCLUDES variable: ${INCLUDES}")
	foreach(items ${INCLUDES})
		file(GLOB_RECURSE INCLUDES_SRC "${items}/*.cpp")
	endforeach()
	message("util_tools: External INCLUDES sources: ${INCLUDES_SRC}")
endif()

set(util_tools_INCLUDES ${util_tools_INCLUDES}
	${INCLUDES}
	${CUSTOM_INCLUDES}
)

set(util_tools_INCLUDES ${util_tools_INCLUDES} PARENT_SCOPE)
message("util_tools: util_tools_INCLUDES: ${util_tools_INCLUDES}")

include_directories("${util_tools_INCLUDES}")

# end of includes set up

add_subdirectory ("numbers_transform")
add_subdirectory ("numbers_average")
add_subdirectory ("numbers_mixer")

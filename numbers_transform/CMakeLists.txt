# CMakeList.txt : CMake project for numbers_transform, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(numbers_transform)

set(CMAKE_CXX_STANDARD 20)

option(numbers_transform_INHERIT_PARENT_SRC "Adds all parent's source files" OFF)
option(numbers_transform_INHERIT_PARENT_LIBS "Adds all parent's libraries" ON)

message("numbers_transform: numbers_transform_INHERIT_PARENT_SRC is ${numbers_transform_INHERIT_PARENT_SRC}")
message("numbers_transform: numbers_transform_INHERIT_PARENT_LIBS is ${numbers_transform_INHERIT_PARENT_LIBS}")

if (LOG_ON)
	add_compile_definitions("LOG_ON")
endif ()

file(GLOB SRC "*.cpp")

# Inherit parent sources logic
set(PARENT_SRC ${PARENT_SRC} ${SRC})
set(PARENT_SRC ${PARENT_SRC} PARENT_SCOPE)

if (numbers_transform_INHERIT_PARENT_SRC)
	set(SRC ${PARENT_SRC})
	message("'Project' numbers_transform PARENT_SRC: ${PARENT_SRC}")
endif()
# End of Inherit parent sources logic

# Inherit parent libs logic
set(PARENT_LIBS ${PARENT_LIBS} ${LIBS})
set(PARENT_LIBS ${PARENT_LIBS} PARENT_SCOPE)

if (numbers_transform_INHERIT_PARENT_LIBS)
	set(LIBS ${PARENT_LIBS})
	message("'Project' numbers_transform PARENT_LIBS: ${PARENT_LIBS}")
endif()
# End of Inherit parent libs logic

add_executable (numbers_transform ${SRC} ${HEADERS})

# Link all librariles including inherited
set(cnt 1)
foreach(item ${LIBS})
	if (${cnt} EQUAL 1)
		message("Link library '${item}'")
		set(lib_name ${item})
	elseif(${cnt} EQUAL 2)
		message("Library '${lib_name}' path: ${item}")
		set(lib_path ${item})
	elseif(${cnt} EQUAL 3)
		message("Library '${lib_name}' binary path: ${item}")
		#add_subdirectory("${lib_path}" "${item}")
		target_link_libraries(numbers_transform ${lib_name})
	endif()
	MATH(EXPR cnt "${cnt}+1")
endforeach()

# Set and add includes
if (NOT "${INCLUDES}" STREQUAL "")
	message("Add extra includes: ${INCLUDES}")
endif()

set(numbers_transform_INCLUDES ${numbers_transform_INCLUDES}
	${CUSTOM_INCLUDES}
	${INCLUDES}
)
set(numbers_transform_INCLUDES ${numbers_transform_INCLUDES} PARENT_SCOPE)

if (NOT "${numbers_transform_INCLUDES}" STREQUAL "")
	message("numbers_transform_INCLUDES generated: ${numbers_transform_INCLUDES}")
	include_directories("${numbers_transform_INCLUDES}")
endif()

file(GLOB HEADERS "*.h")




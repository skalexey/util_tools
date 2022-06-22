# CMakeList.txt : CMake project for numbers_average, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project(numbers_average)

set(CMAKE_CXX_STANDARD 20)

option(numbers_average_INHERIT_PARENT_SRC "Adds all parent's source files" OFF)
option(numbers_average_INHERIT_PARENT_LIBS "Adds all parent's libraries" ON)

message("numbers_average: numbers_average_INHERIT_PARENT_SRC is ${numbers_average_INHERIT_PARENT_SRC}")
message("numbers_average: numbers_average_INHERIT_PARENT_LIBS is ${numbers_average_INHERIT_PARENT_LIBS}")

if (LOG_ON)
	add_compile_definitions("LOG_ON")
endif ()

file(GLOB SRC "*.cpp")

# Inherit parent sources logic
set(PARENT_SRC ${PARENT_SRC} ${SRC})
set(PARENT_SRC ${PARENT_SRC} PARENT_SCOPE)

if (numbers_average_INHERIT_PARENT_SRC)
	set(SRC ${PARENT_SRC})
	message("'Project' numbers_average PARENT_SRC: ${PARENT_SRC}")
endif()
# End of Inherit parent sources logic

# Inherit parent libs logic
set(PARENT_LIBS ${PARENT_LIBS} ${LIBS})
set(PARENT_LIBS ${PARENT_LIBS} PARENT_SCOPE)

if (numbers_average_INHERIT_PARENT_LIBS)
	set(LIBS ${PARENT_LIBS})
	message("'Project' numbers_average PARENT_LIBS: ${PARENT_LIBS}")
endif()
# End of Inherit parent libs logic

add_executable (numbers_average ${SRC} ${HEADERS})

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
		target_link_libraries(numbers_average ${lib_name})
	endif()
	MATH(EXPR cnt "${cnt}+1")
endforeach()

# Set and add includes
if (NOT "${INCLUDES}" STREQUAL "")
	message("Add extra includes: ${INCLUDES}")
endif()

set(numbers_average_INCLUDES ${numbers_average_INCLUDES}
	${CUSTOM_INCLUDES}
	${INCLUDES}
)
set(numbers_average_INCLUDES ${numbers_average_INCLUDES} PARENT_SCOPE)

if (NOT "${numbers_average_INCLUDES}" STREQUAL "")
	message("numbers_average_INCLUDES generated: ${numbers_average_INCLUDES}")
	include_directories("${numbers_average_INCLUDES}")
endif()

file(GLOB HEADERS "*.h")




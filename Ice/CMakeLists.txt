cmake_minimum_required(VERSION 3.10)
project(Ice)

add_subdirectory(vendor/spdlog)

set (CMKAE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (SOURCE_DIR  "${CMAKE_CURRENT_LIST_DIR}/src") 
set (INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set (SPDLOG_INC  "${CMAKE_CURRENT_LIST_DIR}/vendor/spdlog/include")

message("${SOURCE_DIR}")
message("${INCLUDE_DIR}")
message("${SPDLOG_INC}")

include_directories(
	${INCLUDE_DIR}
	${INCLUDE_DIR}/Ice
	${SPDLOG_INC}
) 


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE SRC_FILES
    "${SOURCE_DIR}/Ice/*.cpp"
)

file (GLOB_RECURSE INC_FILES
    "${INCLUDE_DIR}/*.h"
    "${INCLUDE_DIR}/Ice/*.h"
)

if (WIN32)
	source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SRC_FILES})
	source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${INC_FILES})

elseif (UNIX)
#nothing to do

endif ()

if (WIN32)
	list(APPEND EXTRA_LIBS

	)
elseif (UNIX)
	list (APPEND EXTRA_LIBS
	)
endif ()

add_library(${PROJECT_NAME}_static STATIC ${SRC_FILES} ${INC_FILES})
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME "Ice")
set_target_properties(${PROJECT_NAME}_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_library(${PROJECT_NAME} SHARED ${SRC_FILES} ${INC_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Ice")
set_target_properties(${PROJECT_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# Add the target includes for MY_PROJECT 
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})


#===================== LINKING LIBRARIES =======================#
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})

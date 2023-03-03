cmake_minimum_required(VERSION 3.10)
project(Sandbox)

add_subdirectory(Ice)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE Debug)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set (SOURCE_DIR "${CMAKE_CURRENT_LIST_DIR}/src") 
set (INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")
set (ICE_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/Ice/include")
set (SPDLOG_INC  "${CMAKE_CURRENT_LIST_DIR}/Ice/vendor/spdlog/include")

include_directories(
    ${INCLUDE_DIR}
    ${ICE_INCLUDE_DIR}
    ${SPDLOG_INC}
) 

file(GLOB_RECURSE SRC_FILES
    "${SOURCE_DIR}/*.cpp"
)

file (GLOB_RECURSE INC_FILES
    "${INCLUDE_DIR}/*.h"
)

if (WIN32)
	source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SRC_FILES})
	source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${INC_FILES})

elseif (UNIX)
#nothing to do
endif ()

if(WIN32)
    list(APPEND EXTRA_LIBS
)
elseif(UNIX)
    list(APPEND EXTRA_LIBS
    )
endif()

# Add the executable
if (WIN32) 
	add_executable(${PROJECT_NAME} ${SRC_FILES} ${INC_FILES})
elseif(UNIX)
	add_executable(${PROJECT_NAME} ${SRC_FILES} ${INC_FILES})
endif()

# Add the target includes for MY_PROJECT 
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCE_DIR})


#===================== LINKING LIBRARIES =======================#
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS} Ice)

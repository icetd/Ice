cmake_minimum_required(VERSION 3.10)
project(Ice)

add_subdirectory(vendor/spdlog)
add_subdirectory(vendor/glfw)

if (WIN32)
add_definitions( -DICE_ENABLE_ASSERTS -DICE_DEBUG -DICE_PLATFORM_WINDOWS)
endif()

set (CMKAE_CXX_STANDARD 14)
set (CMAKE_BUILD_TYPE Debug)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set (SOURCE_DIR  "${CMAKE_CURRENT_LIST_DIR}/src") 
set (INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

set (SPDLOG_INC  "${CMAKE_CURRENT_LIST_DIR}/vendor/spdlog/include")
set (GLFW_INC	 "${CMAKE_CURRENT_LIST_DIR}/vendor/glfw/include")

message("${SOURCE_DIR}")
message("${INCLUDE_DIR}")
message("${SPDLOG_INC}")

include_directories(
	${INCLUDE_DIR}
	${INCLUDE_DIR}/Ice
	${INCLUDE_DIR}/Core
	${INCLUDE_DIR}/Renderer
	${INCLUDE_DIR}/Platform/OpenGL
	${INCLUDE_DIR}/Platform/Windows

	${SPDLOG_INC}
	${GLFW_INC}
) 


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

file(GLOB_RECURSE SRC_FILES
    "${SOURCE_DIR}/Ice/Core/*.cpp"
    "${SOURCE_DIR}/Ice/Renderer/*.cpp"
    "${SOURCE_DIR}/Platform/OpenGL/*.cpp"
    "${SOURCE_DIR}/Platform/Windows/*.cpp"
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
		opengl32 glfw
 	)
elseif (UNIX)
	list (APPEND EXTRA_LIBS
		"-lGL -lGLU -lX11 glfw3"
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

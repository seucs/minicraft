cmake_minimum_required(VERSION 3.6)
project(Minecraft)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp head/Cube.h head/Param.h head/Point.h head/TexCube.h head/visualBall.h head/Man.h head/LightMaterial.h head/Label.h head/CubeManager.h head/Crawler.h)
add_executable(Minecraft ${SOURCE_FILES})


IF(APPLE)
    INCLUDE_DIRECTORIES ( /System/Library/Frameworks )
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(GLUT_LIBRARY GLUT )
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL )
    MARK_AS_ADVANCED (COCOA_LIBRARY
            GLUT_LIBRARY
            OpenGL_LIBRARY)
    SET(EXTRA_LIBS ${COCOA_LIBRARY} ${GLUT_LIBRARY} ${OpenGL_LIBRARY})
ENDIF (APPLE)
target_link_libraries(Minecraft ${EXTRA_LIBS})

set (source "${CMAKE_SOURCE_DIR}/img")
set (destination "${CMAKE_CURRENT_BINARY_DIR}/img")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "symbolic link resources folder from ${source} => ${destination}"
)
cmake_minimum_required(VERSION 3.17)
project(openglcpp_g1)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SRC
        "src/*.cpp"
        )

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SRC})

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(external/glfw)
target_include_directories(${PROJECT_NAME}
        PUBLIC external/glfw/include
        PUBLIC external/glm/
        PUBLIC ${GLEW_INCLUDE_DIRS}
        PRIVATE include/
        )
target_link_directories(${PROJECT_NAME}
        PRIVATE external/glfw/src
        PRIVATE external/glm/test
        )

target_link_libraries(${PROJECT_NAME}
        glfw
        ${GLEW_LIBRARIES}
        ${OPENGL_LIBRARIES}
        )

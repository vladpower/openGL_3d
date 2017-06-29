project(Converter)
cmake_minimum_required(VERSION 2.6)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/../)
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} "deferxx" "glm")
add_definitions(-Wall -O2 -std=c++14)

file(GLOB CPPS "src/*.cpp" "src/utils/*.cpp" "deferxx/*.cpp")

add_executable(${PROJECT_NAME} ${CPPS})
target_link_libraries(${PROJECT_NAME} sfml-window  sfml-graphics sfml-system GLEW GLU m GL pthread dl drm Xdamage Xfixes X11 xcb xcb-glx xcb-dri2 Xxf86vm Xext X11 Xau Xdmcp)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

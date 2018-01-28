cmake_minimum_required(VERSION 3.0.0)
project(IdolSchemeProj VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 11) # Sets STD to version 11
include(CTest)
enable_testing()

file(GLOB_RECURSE IdolSchemeProj_SOURCES "src/*.cpp" "/usr/local/include/SOIL/SOIL.c")
file(GLOB_RECURSE IdolSchemeProj_HEADERS "include/*.h" "include/*.hpp")

set(IdolSchemeProj_INCLUDE_DIRS "")
foreach(_headerFile ${IdolSchemeProj_HEADERS}) # Adds each Header to list
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND IdolSchemeProj_INCLUDE_DIRS ${_dir})
endforeach(_headerFile ${IdolSchemeProj_HEADERS})

list(REMOVE_DUPLICATES IdolSchemeProj_INCLUDE_DIRS)

# Compiles glad.c before Source files.
add_executable(IdolScheme "src/glad.c" ${IdolSchemeProj_SOURCES})

### Linking

LINK_DIRECTORIES(GLFW_DIR STATIC "/usr/local/include/GLFW")
LINK_DIRECTORIES(KHR_DIR STATIC "/usr/local/include/KHR")
LINK_DIRECTORIES(GLAD_DIR STATIC "/usr/local/include/glad")
LINK_DIRECTORIES(GLM_DIR STATIC "/usr/local/include/glm")
LINK_DIRECTORIES(SOIL_DIR STATIC "/usr/local/include/SOIL.h")

target_include_directories(IdolScheme PRIVATE ${IdolSchemeProj_INCLUDE_DIRS} GLFW_DIR GLAD_DIR KHR_DIR)
target_link_libraries(IdolScheme glfw3 glfw GL X11 pthread Xrandr Xi dl SOIL)
# Acts like -l  ^

### !Linking

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
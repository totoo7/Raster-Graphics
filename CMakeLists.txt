cmake_minimum_required(VERSION 3.10.0)
project(Raster-Graphics VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE sources CONFIGURE_DEPENDS
    "src/view/*.cpp"
    "src/services/commands/*.cpp"
    "src/services/images/*.cpp"
    "src/controllers/*.cpp"
    "main.cpp"
)

add_executable(Raster-Graphics ${sources})

list(APPEND includePath 
    "include/view"
    "include/controllers"
    "include/services"
    "include/services/commands"
    "include/services/images"
)

find_package(Doxygen REQUIRED)

if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()


target_include_directories(${PROJECT_NAME} PUBLIC ${includePath})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})
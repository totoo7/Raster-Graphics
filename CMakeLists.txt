cmake_minimum_required(VERSION 3.10.0)
project(Raster-Graphics VERSION 0.1.0 LANGUAGES C CXX)

set(sources 
    main.cpp
    src/view/Interface.cpp
    src/services/commands/Command.cpp
    src/services/commands/HelpCommand.cpp
    src/services/commands/ExitCommand.cpp
    src/controllers/CommandFactory.cpp
)

add_executable(Raster-Graphics ${sources})

list(APPEND includePath 
    "include/view"
    "include/controllers"
    "include/services"
    "include/services/commands"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${includePath})


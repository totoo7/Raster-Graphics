cmake_minimum_required(VERSION 3.10.0)
project(Raster-Graphics VERSION 0.1.0 LANGUAGES C CXX)

set(sources 
    main.cpp
    src/view/Interface.cpp
    src/services/commands/Command.cpp
    src/services/commands/HelpCommand.cpp
    src/services/commands/ExitCommand.cpp
    src/services/commands/LoadCommand.cpp
    src/services/commands/SwitchCommand.cpp
    src/services/commands/AddCommand.cpp
    src/services/commands/ListCommand.cpp
    src/services/commands/NegativeCommand.cpp
    src/services/commands/MonochromeCommand.cpp
    src/services/commands/SaveCommand.cpp
    src/services/commands/SaveAsCommand.cpp
    src/services/commands/FlipCommand.cpp
    src/services/commands/RotateCommand.cpp
    src/services/images/Image.cpp
    src/services/images/PGM.cpp
    src/services/images/ImageFactory.cpp
    src/controllers/CommandFactory.cpp
    src/controllers/Session.cpp
    src/controllers/SessionManager.cpp
)

add_executable(Raster-Graphics ${sources})

list(APPEND includePath 
    "include/view"
    "include/controllers"
    "include/services"
    "include/services/commands"
    "include/services/images"
)

target_include_directories(${PROJECT_NAME} PUBLIC ${includePath})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})


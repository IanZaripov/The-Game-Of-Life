cmake_minimum_required(VERSION 3.10)
project(The_Game_Of_Life)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_TTF_INCLUDE_DIRS}
)

add_executable(The_Game_Of_Life
    source/The_Game_Of_Life.cpp
    source/App.cpp
    source/Game.cpp
    source/Renderer.cpp
    source/Button.cpp
    source/Button.h
)

target_link_libraries(The_Game_Of_Life
    ${SDL2_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)

if(WIN32)
    add_custom_command(TARGET The_Game_Of_Life POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            "${SDL2_LIBRARY}"
            $<TARGET_FILE_DIR:The_Game_Of_Life>
        COMMAND ${CMAKE_COMMAND} -E copy
            "${SDL2_TTF_LIBRARY}"
            $<TARGET_FILE_DIR:The_Game_Of_Life>
    )
endif()
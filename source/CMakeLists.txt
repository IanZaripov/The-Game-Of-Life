cmake_minimum_required(VERSION 3.10)
project(The_Game_Of_Life)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Пути к библиотекам
set(SDL2_ROOT "C:/Users/Ян/source/repos/SDL2")
set(SDL2_TTF_ROOT "C:/Users/Ян/source/repos/SDL2_ttf")

# Подключаем заголовочные файлы
include_directories(
    "${SDL2_ROOT}/include"
    "${SDL2_TTF_ROOT}/include"
)

add_executable(The_Game_Of_Life 
    The_Game_Of_Life.cpp
    App.cpp
    Game.cpp
    Renderer.cpp
    Button.h
    Button.cpp
)

# Линкуем библиотеки напрямую
target_link_libraries(The_Game_Of_Life
    "${SDL2_ROOT}/lib/x64/SDL2.lib"
    "${SDL2_ROOT}/lib/x64/SDL2main.lib"
    "${SDL2_TTF_ROOT}/lib/x64/SDL2_ttf.lib"
)

if(WIN32)
    target_compile_definitions(The_Game_Of_Life PRIVATE "-Dmain=SDL_main")
    
    # Копируем DLL файлы
    set(DLL_FILES 
        "${SDL2_ROOT}/lib/x64/SDL2.dll"
        "${SDL2_TTF_ROOT}/lib/x64/SDL2_ttf.dll"
    )
    
    foreach(DLL_FILE ${DLL_FILES})
        if(EXISTS "${DLL_FILE}")
            add_custom_command(TARGET The_Game_Of_Life POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                    "${DLL_FILE}"
                    $<TARGET_FILE_DIR:The_Game_Of_Life>
            )
        else()
            message(WARNING "DLL not found: ${DLL_FILE}")
        endif()
    endforeach()
endif()
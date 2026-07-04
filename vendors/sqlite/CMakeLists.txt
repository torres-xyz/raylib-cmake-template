include(FetchContent)

FetchContent_Declare(
        sqlite
        URL https://www.sqlite.org/2026/sqlite-amalgamation-3510300.zip
        SYSTEM
)

FetchContent_MakeAvailable(sqlite)

add_library(sqlite)

target_include_directories(sqlite
        SYSTEM
        PUBLIC
        ${sqlite_SOURCE_DIR}
)

target_sources(
        sqlite
        PRIVATE
        ${sqlite_SOURCE_DIR}/sqlite3.h
        ${sqlite_SOURCE_DIR}/sqlite3.c
)
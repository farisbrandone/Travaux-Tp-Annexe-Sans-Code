cmake_minimum_required(VERSION 3.10)
project(SortingAlgorithms VERSION 1.0.0)

# Configuration C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Options de compilation
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

message("CMAKE_BINARY_DIR = ${CMAKE_BINARY_DIR}")
message("CMAKE_SOURCE_DIR = ${CMAKE_SOURCE_DIR}")
message("Exécutables iront dans : ${CMAKE_BINARY_DIR}/bin")

# ============ CRÉER UNE BIBLIOTHÈQUE ============
# Fichiers sources pour la BIBLIOTHÈQUE
set(LIB_SOURCES
    src/quicksort.cpp
    src/binary_search.cpp
)

# Fichiers sources pour l'exécutable principal
set(APP_SOURCES
    src/main.cpp
)

# Fichiers d'en-tête
set(HEADERS
    include/sorting.hpp
)

# 1. Créer une BIBLIOTHÈQUE STATIQUE
add_library(sorting_lib STATIC ${LIB_SOURCES} ${HEADERS})

# Inclure les répertoires pour la bibliothèque
target_include_directories(sorting_lib PUBLIC include)

# 2. Créer l'exécutable principal
add_executable(sorting_demo ${APP_SOURCES})

# Lier l'exécutable à la bibliothèque
target_link_libraries(sorting_demo PRIVATE sorting_lib)

# ============ TESTS ============
enable_testing()
add_subdirectory(tests)
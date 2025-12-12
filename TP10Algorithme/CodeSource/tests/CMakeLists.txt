cmake_minimum_required(VERSION 3.14)
project(SortingTests LANGUAGES CXX)

# Télécharger Google Test automatiquement
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(TEST_SOURCES
    test_sorting.cpp
)

# Créer l'exécutable de test
add_executable(run_tests ${TEST_SOURCES})

# Lier avec Google Test ET notre bibliothèque
target_link_libraries(run_tests PRIVATE 
    sorting_lib          # NOTRE bibliothèque
    gtest_main          # Google Test
)

# Inclure les répertoires
target_include_directories(run_tests PRIVATE 
    ../include
    ${googletest_SOURCE_DIR}/googletest/include
)

# Activer les tests
enable_testing()

# Option 1: Simple (pour CMake 3.10)
add_test(NAME SortingTests COMMAND run_tests)

# Option 2: Avec Google Test (pour CMake 3.14+)
# include(GoogleTest)
# gtest_discover_tests(run_tests)
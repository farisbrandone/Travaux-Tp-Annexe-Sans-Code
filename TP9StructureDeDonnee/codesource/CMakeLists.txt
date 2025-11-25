cmake_minimum_required(VERSION 3.10)
project(DataStructures VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
include_directories(include)

# Sources pour l'exécutable principal
set(MAIN_SOURCES
    src/array.c
    src/linked_list.c
    src/doubly_linked_list.c
    src/stack.c
    src/queue.c
    src/priority_queue.c
    src/bst.c
    src/rbtree.c
    src/graph.c
    src/hash_table.c
    src/tree.c
    src/main.c
)

# Sources pour les tests
set(TEST_SOURCES
    src/array.c
    src/linked_list.c
    src/doubly_linked_list.c
    src/stack.c
    src/queue.c
    src/priority_queue.c
    src/bst.c
    src/rbtree.c
    src/graph.c
    src/hash_table.c
    src/tree.c
    tests/test_structures.c
)

# Exécutable principal
add_executable(datastructures ${MAIN_SOURCES})
target_compile_options(datastructures PRIVATE -Wall -Wextra)

# Exécutable de tests
add_executable(test_structures ${TEST_SOURCES})
target_compile_options(test_structures PRIVATE -Wall -Wextra)

# Option pour exécuter les tests avec CTest
enable_testing()
add_test(NAME StructuresTest COMMAND test_structures)
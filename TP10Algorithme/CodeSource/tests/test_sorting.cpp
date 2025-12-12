#include <gtest/gtest.h>
#include "sorting.hpp"
#include <vector>

// Test simple pour swap
TEST(UtilsTest, Swap) {
    int a = 5, b = 10;
    swap(a, b);
    EXPECT_EQ(a, 10);
    EXPECT_EQ(b, 5);
}

// Test simple pour isSorted
TEST(UtilsTest, IsSorted) {
    std::vector<int> sorted = {1, 2, 3, 4, 5};
    std::vector<int> unsorted = {5, 3, 1, 4, 2};
    
    EXPECT_TRUE(isSorted(sorted));
    EXPECT_FALSE(isSorted(unsorted));
}

// Test simple pour QuickSort
TEST(QuickSortTest, Basic) {
    std::vector<int> arr = {5, 3, 8, 1, 2};
    quickSort(arr, 0, arr.size() - 1);
    
    EXPECT_TRUE(isSorted(arr));
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[4], 8);
}

// Test QuickSort avec tableau vide
TEST(QuickSortTest, EmptyArray) {
    std::vector<int> arr = {};
    quickSort(arr, 0, -1);
    EXPECT_TRUE(isSorted(arr));
}

// Test QuickSort avec un seul élément
TEST(QuickSortTest, SingleElement) {
    std::vector<int> arr = {42};
    quickSort(arr, 0, arr.size() - 1);
    EXPECT_TRUE(isSorted(arr));
    EXPECT_EQ(arr[0], 42);
}

// Test simple pour Binary Search
TEST(BinarySearchTest, Basic) {
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    
    // Éléments qui existent
    EXPECT_EQ(binarySearch(arr, 1), 0);
    EXPECT_EQ(binarySearch(arr, 7), 3);
    EXPECT_EQ(binarySearch(arr, 13), 6);
    
    // Éléments qui n'existent pas
    EXPECT_EQ(binarySearch(arr, 2), -1);
    EXPECT_EQ(binarySearch(arr, 15), -1);
}

// Test Binary Search avec tableau vide
TEST(BinarySearchTest, EmptyArray) {
    std::vector<int> arr = {};
    EXPECT_EQ(binarySearch(arr, 5), -1);
}

// Test d'intégration: QuickSort + Binary Search
TEST(IntegrationTest, SortThenSearch) {
    std::vector<int> arr = {7, 2, 5, 1, 9, 3, 8, 4, 6};
    
    // 1. Trier le tableau
    quickSort(arr, 0, arr.size() - 1);
    EXPECT_TRUE(isSorted(arr));
    
    // 2. Rechercher des éléments
    EXPECT_EQ(binarySearch(arr, 1), 0);    // Premier élément
    EXPECT_EQ(binarySearch(arr, 5), 4);    // Élément au milieu
    EXPECT_EQ(binarySearch(arr, 9), 8);    // Dernier élément
    EXPECT_EQ(binarySearch(arr, 10), -1);  // Non existant
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
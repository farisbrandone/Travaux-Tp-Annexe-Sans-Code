#include "sorting.hpp"
#include <stdexcept>

// Affiche le tableau
void printArray(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        std::cout << arr[i];
        if (i < arr.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Vérifie si le tableau est trié
bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}


// Binary Search itérative
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;  // Trouvé
        }
        
        if (arr[mid] < target) {
            left = mid + 1;  // Chercher à droite
        } else {
            right = mid - 1; // Chercher à gauche
        }
    }
    
    return -1;  // Non trouvé
}
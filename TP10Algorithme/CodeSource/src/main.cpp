#include "sorting.hpp"
#include <iostream>
#include <vector>




// Simulation pas à pas de QuickSort
void simulateQuickSort() {
    std::cout << "\n=== SIMULATION QUICKSORT ===" << std::endl;
    
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    
    std::cout << "Tableau initial: ";
    printArray(arr);
    
    quickSort(arr, 0, arr.size() - 1);
    
    std::cout << "Tableau trié: ";
    printArray(arr);
    
    std::cout << "Vérification: " << (isSorted(arr) ? "✓ TRIÉ" : "✗ NON TRIÉ") << std::endl;
}

// Démonstration Binary Search
void demonstrateBinarySearch() {
    std::cout << "\n=== DEMONSTRATION BINARY SEARCH ===" << std::endl;
    
    // Tableau doit être trié pour binary search
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    std::cout << "Tableau trié: ";
    printArray(arr);
    
    int targets[] = {7, 15, 20, 1};
    
    for (int target : targets) {
        int index = binarySearch(arr, target);
        if (index != -1) {
            std::cout << target << " trouvé à l'index " << index << std::endl;
        } else {
            std::cout << target << " non trouvé" << std::endl;
        }
    }
}

// Menu principal
int main() {
    std::cout << "=== PROJET ALGORITHMES SIMPLE ===" << std::endl;
    std::cout << "1. QuickSort" << std::endl;
    std::cout << "2. Binary Search" << std::endl;
    std::cout << "3. Quitter" << std::endl;
    
    int choice;
    do {
        std::cout << "\nVotre choix: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                simulateQuickSort();
                break;
            case 2:
                demonstrateBinarySearch();
                break;
            case 3:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide!" << std::endl;
        }
    } while (choice != 3);
    
    return 0;
}
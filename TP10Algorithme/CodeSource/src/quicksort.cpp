#include "sorting.hpp"

// Échange deux éléments
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partitionnement pour QuickSort
int partition(std::vector<int>& arr, int left, int right) {
    // Prendre le dernier élément comme pivot
    int pivot = arr[right];
    
    // Index de l'élément plus petit
    int i = left - 1;
    
    for (int j = left; j < right; j++) {
        // Si l'élément courant est plus petit que le pivot
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Placer le pivot à la bonne position
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

// QuickSort récursif
void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Partitionner le tableau
        int pivotIndex = partition(arr, left, right);
        
        // Trier récursivement les deux parties
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}
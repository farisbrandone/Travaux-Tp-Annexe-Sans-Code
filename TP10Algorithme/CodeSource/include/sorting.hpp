#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <iostream>

// Fonction QuickSort simple
void quickSort(std::vector<int>& arr, int left, int right);

// Fonction utilitaire pour QuickSort
int partition(std::vector<int>& arr, int left, int right);

// Fonction Binary Search simple
int binarySearch(const std::vector<int>& arr, int target);

// Fonctions utilitaires
bool isSorted(const std::vector<int>& arr);
void printArray(const std::vector<int>& arr);
void swap(int& a, int& b);

#endif // SORTING_HPP
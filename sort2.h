

#ifndef sort_h
#define sort_h

#include <vector>
#include <string>

using Val = int;
using Container = std::vector<Val>;
using Iter = long;

int insertionSort(Container& arr, Iter start, Iter end);
/*
int mergeSort(Container& arr, Iter start, Iter end);
int quickSort(Container& arr, Iter start, Iter end);
int shellSort(Container& arr, Iter start, Iter end);
int partition(Container& a, Iter st, Iter nd); //helper funtion for quicksort
void print(const Container& arr,int len); //helper function
*/
#endif



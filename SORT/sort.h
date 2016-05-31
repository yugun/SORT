#ifndef __SORT_H__
#define __SORT_H__

template <class T>
void swap(T& left, T& right);
bool isNonDecreasing(int* array, int length);
void bubble_sort(int* array, int length);
void selection_sort(int* array, int length);
void insertion_sort(int* array, int length);

#endif

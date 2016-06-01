#ifndef __SORT_H__
#define __SORT_H__

template <class T>
void swap(T& left, T& right);
bool isNonDecreasing(int* array, int length);
void bubble_sort(int* array, int length);
void selection_sort(int* array, int length);
void insertion_sort(int* array, int length);
void quick_sort(int* array, int start, int end);
int partition(int* array, int start, int end);
void merge_sort(int* array, int start, int end);
void merge(int* array, int start, int mid, int end);

#endif

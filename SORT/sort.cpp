#include <climits>
#include <algorithm>

#include "sort.h"

template <class T>
void swap(T& left, T& right){
	T temp = left;
	left = right;
	right = temp;
}

bool isNonDecreasing(int* array, int length){
	for(int i = 0; i < length-1; i ++)
		if(array[i] > array[i+1])
			return false;
	return true;
}
/* Bubble sort

*/
void bubble_sort(int* array, int length){
	for(int i = 0; i < length-1; i ++)
		for(int j = 0; j < length-1; j ++)
			if(array[j] > array[j+1])
				swap(array[j], array[j+1]);
}
/* Selection sort

*/
void selection_sort(int* array, int length){
	for(int i = 0; i < length; i ++){
		int minIndex = i;
		for(int j = i+1; j < length; j ++)
			if(array[minIndex] > array[j])
				minIndex = j;
		swap(array[minIndex], array[i]);
	}
}
/* Insertion sort

*/
void insertion_sort(int* array, int length){
	for(int i = 1; i < length; i ++){
		int index = i;
		for(int j = i-1; j >= 0; j --){
			if(array[index] < array[j])
				swap(array[index--], array[j]);
			else
				break;
		}
	}
}
/* Quick sort

*/
int partition(int* array, int start, int end){
	int pivot = start;
	int lastSmall = start+1;
	for(int i = lastSmall; i < end; i ++){
		if(array[pivot] > array[i])
			swap(array[lastSmall++], array[i]);
	}
	swap(array[pivot], array[lastSmall]);
	return lastSmall;
}
void quick_sort(int* array, int start, int end){
	if(start < end){	
		int pivot = partition(array, start, end);
		quick_sort(array, start, pivot-1);
		quick_sort(array, pivot+1, end);
	}
}
/* Merge sort

*/
/* Heap sort

*/

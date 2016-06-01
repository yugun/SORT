#include <iostream>
#include <cstdlib>
#include <cstring>

#include "sort.h"
#include "visualize.h"

#define ARRSIZE		30	

typedef int keyType;
using namespace std;

void array_randInit(int* array, int length);
void array_print(int* array, int length);
int main(int argc, char** argv){
	int array[ARRSIZE];
	array_randInit(array, ARRSIZE);

	// print non-ordered array
//	array_print(array, ARRSIZE);
	visualizeArray(array, ARRSIZE);

//	select sort algorithm
//	bubble_sort(array, ARRSIZE);
//	selection_sort(array, ARRSIZE);
//	insertion_sort(array, ARRSIZE);
//	quick_sort(array, 0, ARRSIZE);
	merge_sort(array, 0, ARRSIZE);

	// print ordered array
//	array_print(array, ARRSIZE);
	visualizeArray(array, ARRSIZE);
	
	cout << "Is array non-decreasing? : " 
	<< (isNonDecreasing(array, ARRSIZE)? "true":"false") << endl;

	return 0;
}

void array_randInit(int* array, int length){
	srand(time(NULL));
	bool checked[ARRSIZE];
	memset(checked, 0, sizeof(checked));
	
	for(int i = 0; i < ARRSIZE; i ++){
		int randNumber = rand()%ARRSIZE + 1;
		while(checked[randNumber-1])
			randNumber = randNumber%ARRSIZE + 1;
		checked[randNumber-1] = true;
		array[i] = randNumber;
	}
}
void array_print(int* array, int length){
	for(int i = 0; i < ARRSIZE; i ++)
		cout << array[i] << " ";
	cout << endl;
}

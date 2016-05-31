#include <iostream>
#include <cstdlib>
#include <cstring>

#include "sort.h"
#include "visualize.h"

#define ARRSIZE		30	

typedef int keyType;
using namespace std;

int main(int argc, char** argv){
	// init
	srand(time(NULL));
	int array[ARRSIZE];
	bool checked[ARRSIZE];
	memset(checked, 0, sizeof(checked));
	
	for(int i = 0; i < ARRSIZE; i ++){
		int randNumber = rand()%ARRSIZE + 1;
		while(checked[randNumber-1])
			randNumber = randNumber%ARRSIZE + 1;
		checked[randNumber-1] = true;
		array[i] = randNumber;
	}

/*
	// print non-ordered array
	for(int i = 0; i < ARRSIZE; i ++){
		cout << array[i] << " ";
	}
	cout << endl;
*/
	
	visualizeArray(array, ARRSIZE);

//	select sort algorithm
//	bubble_sort(array, ARRSIZE);
//	selection_sort(array, ARRSIZE);
//	insertion_sort(array, ARRSIZE);
	quick_sort(array, 0, ARRSIZE);

	//visualizeArray(array, ARRSIZE);
	

	// print ordered array
	for(int i = 0; i < ARRSIZE; i ++){
		cout << array[i] << " ";
	}
	cout << endl << "is array non-decreasing? : " 
	<< (isNonDecreasing(array, ARRSIZE)? "true":"false") << endl;

	return 0;
}

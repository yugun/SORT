#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "visualize.h"

using std::cout;
using std::endl;

void visualizeArray(int* const array, int length){
	char* line = new char[length];
	int maxIndex = 0;

	// initialize line
	memset(line, ' ', sizeof(char)*length);

	// find maxIndex
	for(int i = 1; i < length; i ++)
		if(array[maxIndex] < array[i])
			maxIndex = i;
	
	for(int i = array[maxIndex]; i > 0; i --){
		for(int j = 0; j < length; j ++)
			if(array[j] >= i)
				line[j] = '*';

		cout << line << endl;		
	}

	delete [] line;
}


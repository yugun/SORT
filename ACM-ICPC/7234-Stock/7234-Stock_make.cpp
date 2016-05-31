#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAX_N		1000*1000
#define MAX_STOCK	10*1000

using namespace std;

int main(){
	freopen("7234-Stock_in.txt", "w", stdout);
	srand(time(NULL));

	const int T = 10;
	cout << T << endl;

	for(int test_cases = 0; test_cases < T; test_cases ++){
		const int n = MAX_N;
		cout << n << endl;
		
		const int stock = MAX_STOCK;
		for(int i = 0; i < n; i ++)
			cout << rand()%(stock) << " ";
		cout << endl;
	}
	
	return 0;
}

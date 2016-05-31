#include <iostream>
#include <cstdio>

#define MAX_N	1000*1000
using namespace std;

int T, n;
int stock[MAX_N];
long long max_profit(int start, int end){
	// find max
	int maxValue = stock[start];
	int maxIndex = start;
	long long profit = 0;
	for(int i = start+1; i < end; i ++){
		if(maxValue < stock[i]){
			maxValue = stock[i];
			maxIndex = i;
		}
	}

	if(maxIndex != end-1)
		profit += max_profit(maxIndex+1, end);

	profit += (maxIndex-start)*stock[maxIndex];
	for(int i = start; i < maxIndex; i ++)
		profit -= stock[i];

	return profit;
}
int main(){
//	freopen("7234-Stock_in.txt", "r", stdin);

	cin >> T;
	for(int test_cases = 0; test_cases < T; test_cases ++){
		cin >> n;
		for(int i = 0; i < n; i ++)
			cin >> stock[i];

		cout << max_profit(0, n) << endl;
	}

	return 0;
}

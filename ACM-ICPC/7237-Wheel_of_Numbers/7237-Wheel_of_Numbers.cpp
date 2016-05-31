#include <iostream>
#include <cstdio>

#define MAX_N	100
#define MAX_M	9

using namespace std;

int T, n, m;
int Z;
int wheel[MAX_N];
int cache[MAX_N];
int ten_pow(int exp){ if(exp == 0) return 1;
	else return 10*ten_pow(exp-1);
}
int get_wheel(int start, int digit){
	if(start == n) start = 0;
	if(digit == 1) return wheel[start];
	else return wheel[start]*ten_pow(digit-1) + get_wheel(start+1, digit-1);
}
int get_wheel2(int end){
	if(end == m-1) return get_wheel(0, m);
	if(end >= n) end -= n;
	return (Z*10 + wheel[end]) % ten_pow(m);
}
int main(){
	freopen("7237-Wheel_of_Numbers_in.txt", "r", stdin);

	cin >> T;
	for(int test_cases = 0; test_cases < T; test_cases ++){
		cin >> n >> m;

		int X = 0, Y = 0, temp;
		for(int i = 0; i < m; i ++){
			cin >> temp;
			X += temp*ten_pow(m-i-1);
		}
		for(int i = 0; i < m; i ++){
			cin >> temp;
			Y += temp*ten_pow(m-i-1);
		}
		for(int i = 0; i < n; i ++)
			cin >> wheel[i];

		int count = 0;

		for(int i = 0; i < n; i ++){
			Z = get_wheel(i, m);
			if(Z >= X && Z <= Y)
				count ++;
		}

		/*
		Z = 0;
		for(int i = m-1; i < n+m-1; i ++){
			Z = get_wheel2(i);
			cout << Z << endl;
			if(Z >= X && Z <= Y)
				count ++;
		}
		*/
		//clock_t end = clock();
		//printf("%lf\n", (double)end - start);
		cout << count << endl;

	}
	return 0;
}

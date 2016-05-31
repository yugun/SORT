#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> slice(const vector<int> v, int a, int b){
	return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrder(const vector<int>& preorder,
					const vector<int>& inorder){
	const int N = preorder.size();
	if(preorder.empty()) return;

	const int root = preorder[0];
	const int L = find(inorder.begin(), inorder.end(), root)
					- inorder.begin();
	
	const int R = N - 1 - L;

	printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));

	cout << root << ' ';
}
int main(){
	vector<int> preorder;
	vector<int> inorder;

	int preArr[10] = { 27, 16, 9, 12, 54, 36, 72, };
	int inArr[10] = { 9, 12, 16, 27, 36, 54, 72, };

	for(int i = 0; i < 7; i ++){
		preorder.push_back(preArr[i]);
		inorder.push_back(inArr[i]);
	}
	printPostOrder(preorder, inorder);
	cout << endl;

	return 0;
}

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

struct TreeNode{
	int label;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){ label = rand()%45; }
	TreeNode(int label){ this->label = label; }
};
void printLable(TreeNode* root){
	if(root->left != NULL) printLable(root->left);
	if(root->right != NULL) printLable(root->right);
	cout << root->label << endl;
}
int height(TreeNode* root){
	int h = 0;
	if(root->left != NULL) h = max(h, 1 + height(root->left));
	if(root->right != NULL) h = max(h, 1 + height(root->right));

	return h;
}

int main(){
	TreeNode* root = new TreeNode(27);
	root->left = new TreeNode(16);
	root->right = new TreeNode(54);
	root->left->left = new TreeNode(9);
	root->left->left->right = new TreeNode(12);
	root->right->left = new TreeNode(36);
	root->right->right = new TreeNode(72);
	
	printLable(root);
	cout << height(root) << endl;
	
	return 0;
}

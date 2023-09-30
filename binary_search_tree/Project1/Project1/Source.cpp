#include<iostream>
#include<vector>
#include "BST.h"
using namespace std;

int main() {
	BST bst = { 5,4,8,2,10,9,7,11,25 };

	cout << "inorder" << endl;
	bst.inorder_print();
	cout << endl;

	cout << "preorder" << endl;
	bst.preorder_print();
	cout << endl;

	cout << "postorder" << endl;
	bst.postorder_print();
	cout << endl;

	cout << "maximum" << endl;
	cout<< *bst.maximum() <<endl;

	cout << "minimum" << endl;
	cout << *bst.minimum() << endl;;
	

	cout << "更玡竚++龟successor" << endl;
	BST::iterator it1 = bst.minimum();
	cout << *it1 << endl;
	cout << *(++it1) << endl;
	cout << *(++it1) << endl;
	cout << *(it1) << endl;


	cout << "更竚++龟successor" << endl;
	BST::iterator it2 = bst.minimum();
	cout << *it2 << endl;
	cout << *(it2++) << endl;
	cout << *(it2++) << endl;
	cout << *(it2) << endl;

	cout << "更玡竚--龟prdecessor" << endl;
	BST::iterator it3 = bst.maximum();
	cout << *it3 << endl;
	cout << *(--it3) << endl;
	cout << *(--it3) << endl;
	cout << *(it3) << endl;


	cout << "更竚--龟prdecessor" << endl;
	BST::iterator it4 = bst.maximum();
	cout << *it4 << endl;
	cout << *(it4--) << endl;
	cout << *(it4--) << endl;
	cout << *(it4) << endl;

	cout << "insert" << endl;
	bst.insert(15);
	cout << *++it4 << endl;
	cout << *++it4 << endl;
	cout << *++it4 << endl;
	bst.inorder_print();
	cout << endl;

	cout << "remove" << endl;
	BST::iterator it5=bst.remove(----bst.maximum());
	cout << *it5 << endl;
	bst.inorder_print();

	return 0;
}
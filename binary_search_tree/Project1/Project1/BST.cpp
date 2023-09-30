#include "BST.h"
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

TreeNode::TreeNode(int key, TreeNode* parent = NULL, TreeNode* left = NULL, TreeNode* right = NULL) {
	this->key = key;
	this->parent = parent;
	this->left = left;
	this->right = right;
}


BST::iterator::iterator(TreeNode* current) {
	this->current = current;
}

int BST::iterator::operator*() {
	return current->key;
}

BST::iterator& BST::iterator::operator++() { //前置
	if (current->right != NULL) {
		current = current->right;
		while (current->left != NULL) current = current->left;
		return *this;
	}
	else {
		TreeNode* parent = current->parent;
		while (parent != NULL && current == parent->right) {
			current = parent;
			parent = parent->parent;
		}
		current = parent;
		return *this;
	}
	
}

BST::iterator BST::iterator::operator++(int) { //後置
	iterator temp = *this;

	iterator now = current;
	++now;
	*this = now;

	return temp;
}


BST::iterator& BST::iterator::operator--() { //前置
	if (current->left != NULL) {
		current = current->left;
		while (current->right != NULL) current = current->right;
		return *this;
	}
	else {
		TreeNode* parent = current->parent;
		while (parent != NULL && current == parent->left) {
			current = parent;
			parent = parent->parent;
		}
		current = parent;
		return *this;
	}

}

BST::iterator BST::iterator::operator--(int) { //後置
	iterator temp = *this;

	iterator now = current;
	--now;
	*this = now;

	return temp;
}

TreeNode* BST::iterator::get_current() const {
	return current;
}


BST::BST(initializer_list<int> input) {
	vector<int> input_arr(input.begin(), input.end());
	sort(input_arr.begin(), input_arr.end());

	_recursive_init(0, input_arr.size(), input_arr, root);
}

void BST::_recursive_init(int start, int end, vector<int>& input_arr, TreeNode* node) {
	if (start >= end) return;

	int mid = (start + end) / 2;

	TreeNode* new_node = new TreeNode(input_arr[mid]);

	if (node == NULL) root = new_node;
	else {
		if (new_node->key < node->key) node->left = new_node;
		else node->right = new_node;

		new_node->parent = node;
	}
	_recursive_init(start, mid, input_arr, new_node);
	_recursive_init(mid+1, end, input_arr, new_node);
}

void BST::inorder_print() {
	inorder_print(root);
}
void BST::inorder_print(TreeNode* start_node) {
	if (start_node != NULL) {
		inorder_print(start_node->left);
		cout << start_node->key << " ";
		inorder_print(start_node->right);
	}
}

void BST::preorder_print() {
	preorder_print(root);
}
void BST::preorder_print(TreeNode* start_node) {
	if (start_node != NULL) {
		cout << start_node->key << " ";
		preorder_print(start_node->left);
		preorder_print(start_node->right);
	}
}

void BST::postorder_print() {
	postorder_print(root);
}
void BST::postorder_print(TreeNode* start_node) {
	if (start_node != NULL) {
		postorder_print(start_node->left);
		postorder_print(start_node->right);
		cout << start_node->key << " ";
	}
}

BST::iterator BST::minimum() {
	return minimum(root);
}
BST::iterator BST::minimum(TreeNode* node) {
	while (node->left != NULL) node = node->left;
	return node;
}

BST::iterator BST::maximum() {
	return maximum(root);
}
BST::iterator BST::maximum(TreeNode* node) {
	while (node->right != NULL) node = node->right;
	return node;
}


void BST::insert(int key) {
	TreeNode* new_node = new TreeNode(key);

	TreeNode* current_node = root;
	TreeNode* parent_node = NULL;
	while (current_node != NULL) {
		parent_node = current_node;
		if (new_node->key < current_node->key)current_node = current_node->left;
		else current_node = current_node->right;
	}

	new_node->parent = parent_node;

	if (parent_node == NULL) root = new_node;
	else if (new_node->key < parent_node->key) parent_node->left = new_node;
	else parent_node->right = new_node;
}


void BST::_transplant(TreeNode* replaced_node, TreeNode* new_node) {
	if (replaced_node->parent == NULL) root = new_node;
	else if (replaced_node == replaced_node->parent->left)replaced_node->parent->left = new_node;
	else replaced_node->parent->right = new_node;

	if (new_node != NULL) new_node->parent = replaced_node->parent;
}

BST::iterator BST::remove(iterator node) {
	TreeNode* current = node.get_current();
	node++;

	if (current->left == NULL) _transplant(current, current->right);
	else if (current->right == NULL) _transplant(current, current->left);
	else {
		TreeNode* change_node = minimum(current->right).get_current();
		if (current != change_node->right) {
			_transplant(change_node, change_node->right);
			change_node->right = current->right;
			change_node->right->parent = change_node;
		}
		_transplant(current, change_node);
		change_node->left = current->left;
		change_node->left->parent = change_node;

		delete current;
	}
	
	return node;
}
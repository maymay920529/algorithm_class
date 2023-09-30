#pragma once
#include<iostream>
#include<vector>
using namespace std;

class TreeNode {
	friend class BST;
private:
	int key;
	TreeNode* parent;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int key, TreeNode* parent, TreeNode* left, TreeNode* right);
};




class BST {
private:
	TreeNode* root = NULL;
	void _recursive_init(int start, int end, vector<int>& input, TreeNode* node);
	void _transplant(TreeNode* replaced_node, TreeNode* new_node);

public:
	class iterator {
		friend class BST;
	private:
		TreeNode* current;
		TreeNode* get_current() const;
	public:
		iterator(TreeNode* current);

		int operator*();

		//使用++來當作successor
		iterator& operator++();
		iterator operator++(int);

		//使用--來當作predecessor
		iterator& operator--();
		iterator operator--(int);

		
		
	};

	

	BST(initializer_list<int> l);

	//iterator begin();

	void inorder_print();
	void inorder_print(TreeNode* start_node);
	void preorder_print();
	void preorder_print(TreeNode* start_node);
	void postorder_print();
	void postorder_print(TreeNode* start_node);

	iterator minimum();
	iterator minimum(TreeNode* node);

	iterator maximum();
	iterator maximum(TreeNode* node);

	void insert(int key);
	iterator remove(iterator node);




};

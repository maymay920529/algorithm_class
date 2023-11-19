#pragma once
#include<iostream>
using namespace std;



template<class T>
struct Node {
	template<class M>
	friend class DisjointSet;
	public:
		T data;

	private:
		Node* parent;
		int rank;

		Node* next_node;
};


template <class T>
class DisjointSet {
	public:

		typedef Node<T> Node;

		Node* make_set(int new_data);
		Node* find_set(Node* node);
		void union_set(Node* node1, Node* node2);
	
		~DisjointSet();

	private:
		Node* start_node = NULL;
		Node* end_node=NULL;

		void link(Node* node1, Node* node2);
};


template<class T>
Node<T>* DisjointSet<T>::make_set(int new_data) {
	Node* new_node=new Node;

	new_node->data = new_data;
	new_node->parent = new_node;
	new_node->rank = 0;

	if (start_node == NULL) {
		start_node = new_node;
	}
	else {
		end_node->next_node = new_node;
	}

	this->end_node = new_node;
	return new_node;
}

template<class T>
Node<T>* DisjointSet<T>::find_set(Node* node) {
	if (node->parent != node) {
		node->parent = find_set(node->parent);
	}
	return node->parent;
}

template<class T>
void DisjointSet<T>::link(Node* node1, Node* node2) {
	if (node1->rank > node2->rank) {
		node2->parent = node1;
	}
	else {
		node1->parent = node2;

		if (node1->rank == node2->rank) {
			++node2->rank;
		}
	}

}

template<class T>
void DisjointSet<T>::union_set(Node* node1, Node* node2) {
	link(find_set(node1), find_set(node2));
}

template<class T>
DisjointSet<T>::~DisjointSet() {
	Node* curr_node;

	while (this->start_node != this->end_node) {
		curr_node = this->start_node;
		this->start_node = start_node->next_node;
		delete curr_node;
	}

	delete start_node;
	this->start_node = NULL;
	this->end_node = NULL;
}
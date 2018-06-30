#ifndef TREES_AVLTREE_H_
#define TREES_AVLTREE_H_

#include <iostream>
#include <memory>
using uint = unsigned int;

namespace AVL
{
	template <typename T>
	class Node
	{
	public:
		T data;
		Node *left;
		Node *right;
		uint height;

		Node(T d) : data(d), left(nullptr), right(nullptr), height(1)
		{}

		Node(T d, Node *l, Node *r, uint h) : data(d), left(l), right(r), height(h)
		{}

		Node(Node *n) : data(n -> data), left(n -> left), right(n -> right), height(n -> height)
		{}
	};
}

template <typename T>
class AVLTree
{
private:
	AVL::Node<T> *root;

public:
	AVLTree();
	AVLTree(T val);
	AVLTree(const AVLTree &rhs);
	AVLTree(AVLTree &&rhs);
	~AVLTree();
	AVLTree &operator=(const AVLTree &rhs);
	AVLTree &operator=(AVLTree &&rhs);
	bool operator==(const AVLTree &rhs) const;

	void clear();
	void clearRecursive(AVL::Node<T> *recRoot);

	void recursiveCopy(AVL::Node<T> *recRoot, AVL::Node<T> *rhsRecRoot);
	void recursiveCheck(const AVL::Node<T> *recRoot, const AVL::Node<T> *rhsRecRoot, bool &retCond) const;

	void swapNodeVal(AVL::Node<T> *left, AVL::Node<T> *right);
	int balance(AVL::Node<T> *left, AVL::Node<T> *right);
	uint max(AVL::Node<T> *left, AVL::Node<T> *right);

	void append(T val);
	void appendRecursive(AVL::Node<T> *recRoot, T val, bool &appended);
	void leftRotate(AVL::Node<T> *nodeA);
	void leftRightRotate(AVL::Node<T> *nodeA);
	void rightRotate(AVL::Node<T> *nodeA);
	void rightLeftRotate(AVL::Node<T> *nodeA);

	void remove(T val);
	void removeRecursive(AVL::Node<T> *&recRoot, T val);
	AVL::Node<T> *&getSmallestInRightSubTree(AVL::Node<T> *recRoot);

	bool find(T val);
	void findRecursive(AVL::Node<T> *recRoot, T val);

	bool isEmpty();

	void print();
	void postorder(AVL::Node<T> *recRoot, int indent);
};

#include "avlTree.cpp"

#endif /* TREES_AVLTREE_H_ */

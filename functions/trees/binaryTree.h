#ifndef TREES_BINARYTREE_H_
#define TREES_BINARYTREE_H_

#include <iostream>
#include <iomanip>

using uint = unsigned int;

namespace BT
{
	template <typename T>
	class Node
	{
	public:
		T data;
		Node<T> *left;
		Node<T> *right;

		Node() : data(0), left(nullptr), right(nullptr)
		{

		}

		Node(T d) : data(d), left(nullptr), right(nullptr)
		{

		}

		Node(T d, Node<T> *l, Node<T> *r) : data(d), left(l), right(r)
		{

		}

		/*Node(const Node &rhs) : data(rhs.data), left(rhs.left), right(rhs.right)
		{
			std::cout << ">>>calling copy constructor (BT::Node)" << std::endl;
		}

		Node(Node &&rhs) : data(std::move(rhs.data)), left(std::move(rhs.left)), right(std::move(rhs.right))
		{
			std::cout << ">>>calling move constructor (BT::Node)" << std::endl;
		}

		~Node()
		{
			std::cout << ">>>calling destructor (BT::Node)" << std::endl;
		}

		const Node &operator=(const Node &rhs)
		{
			std::cout << ">>>calling copy assignment operator (BT::Node)" << std::endl;

			if(this != &rhs)
			{
				data = rhs.data;
				left = rhs.left;
				right= rhs.right;
			}

			return *this;
		}
		const Node &operator=(Node &&rhs)
		{
			std::cout << ">>>calling move assignment operator (BT::Node)" << std::endl;

			if(this != &rhs)
			{
				data = std::move(rhs.data);
				left = std::move(rhs.left);
				right= std::move(rhs.right);
			}

			return *this;
		}*/
	};
}

template <typename T>
class BinaryTree
{
private:
	BT::Node<T> *root;

public:
	// class functionality
	BinaryTree();
	BinaryTree(T val);
	BinaryTree(const BinaryTree &rhs);
	//BinaryTree(BinaryTree &&rhs);
	~BinaryTree();
	const BinaryTree &operator=(const BinaryTree &rhs);
	//const BinaryTree &operator=(BinaryTree &&rhs);
	bool operator==(const BinaryTree &rhs) const;

	// base binary tree functionality
	void clear();
	void clearRecursive(BT::Node<T> *recRoot);

	void recursiveCopy(BT::Node<T> *recRoot, BT::Node<T> *rhsRecRoot);
	void recursiveCheck(const BT::Node<T> *recRoot, const BT::Node<T> *rhsRecRoot, bool &retCond) const;

	void append(T val);
	void appendRecursive(BT::Node<T> *recRoot, BT::Node<T> *node);

	void remove(T val);
	void removeRecursive(BT::Node<T> *&recRoot, T val);
	BT::Node<T> *&getSmallestInRightSubTree(BT::Node<T> *recRoot);

	bool find(T val);
	void findRecursive(BT::Node<T> *recRoot, T val, bool &retCond);

	bool isEmpty();

	void print();
	void postorder(BT::Node<T>* p, int indent);
};
#include "binaryTree.cpp"

#endif /* TREES_BINARYTREE_H_ */

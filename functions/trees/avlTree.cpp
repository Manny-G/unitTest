#ifdef TREES_AVLTREE_H_
#include "avlTree.h"

template <typename T>
AVLTree<T>::AVLTree()
{
	root = nullptr;
}

template <typename T>
AVLTree<T>::AVLTree(T val)
{
	root = new AVL::Node<T>(val);
}

template <typename T>
AVLTree<T>::AVLTree(const AVLTree<T> &rhs)
{
	std::cout << ">>>Calling copy constructor (AVLTree)" << std::endl;
	clear();

	root = new AVL::Node<T> *(new AVL::Node<T>(rhs.root));
	recursiveCopy(root, rhs.root);
}

template <typename T>
AVLTree<T>::AVLTree(AVLTree<T> &&rhs)
{
	std::cout << ">>>Calling move constructor (AVLTree)" << std::endl;
	root = new AVL::Node<T> *(new AVL::Node<T>(std::move(rhs.root)));
	rhs.clear();
}

template <typename T>
AVLTree<T>::~AVLTree()
{
	std::cout << ">>>Calling destructor (AVLTree)" << std::endl;
	clear();
}

template <typename T>
AVLTree<T> &AVLTree<T>::operator=(const AVLTree<T> &rhs)
{
	std::cout << ">>>Calling copy assignment operator (AVLTree)" << std::endl;

	if(this != &rhs)
	{
		clear();
		root = new AVL::Node<T> *(new AVL::Node<T>(rhs.root));
		recursiveCopy(root, rhs.root);
	}

	return *this;
}

template <typename T>
AVLTree<T> &AVLTree<T>::operator=(AVLTree<T> &&rhs)
{
	std::cout << ">>>Calling move assignment operator (AVLTree)" << std::endl;

	if(this != &rhs)
	{
		clear();
		root = new AVL::Node<T> *(std::move(rhs.root));
		rhs.clear();
	}

	return *this;
}

template <typename T>
void AVLTree<T>::clear()
{
	if(root == nullptr)
		return;

	clearRecursive(root);
}

template <typename T>
void AVLTree<T>::clearRecursive(AVL::Node<T> *recRoot)
{
	if(recRoot == nullptr)
		return;

	clearRecursive(root -> left);
	clearRecursive(root -> right);

	delete recRoot;
}

template <typename T>
void AVLTree<T>::recursiveCopy(AVL::Node<T> *recRoot, AVL::Node<T> *rhsRecRoot)
{
	if(rhsRecRoot == nullptr)
		return;

	recRoot = new AVL::Node<T>(rhsRecRoot);
	recursiveCopy(recRoot -> left, rhsRecRoot -> left);
	recursiveCopy(recRoot -> right, rhsRecRoot -> right);
}

template <typename T>
void AVLTree<T>::recursiveCheck(const AVL::Node<T> *recRoot, const AVL::Node<T> *rhsRecRoot, bool &retCond) const
{}

template <typename T>
void AVLTree<T>::append(T val)
{
	if(root == nullptr)
	{
		root = new AVL::Node<T>(val);
		return;
	}

	bool appended = false;
	appendRecursive(root, val, appended);
}

template <typename T>
void AVLTree<T>::appendRecursive(AVL::Node<T> *recRoot, T val, bool &appended)
{
	if(recRoot == nullptr)
		return;

	if(recRoot -> data < val)
		appendRecursive(recRoot -> left, val, appended);

	else if(recRoot -> data > val)
		appendRecursive(recRoot -> right, val, appended);

	if(appended == false and recRoot -> data < val)
	{
		recRoot -> left = new AVL::Node<T>(val);
		appended = true;
	}

	else if(appended == false and recRoot -> data > val)
	{
		recRoot -> right = new AVL::Node<T>(val);
		appended = true;
	}

	recRoot -> height = 1 + std::max(recRoot -> left -> height, recRoot -> right -> height);

	int balance = recRoot -> left -> height - recRoot -> right -> height;
}

template <typename T>
void AVLTree<T>::remove(T val)
{}

template <typename T>
void AVLTree<T>::removeRecursive(AVL::Node<T> *recRoot, T val)
{}

template <typename T>
AVL::Node<T> *AVLTree<T>::getSmallestInRightSubTree(AVL::Node<T> *recRoot)
{}

template <typename T>
bool AVLTree<T>::find(T val)
{}

template <typename T>
void AVLTree<T>::findRecursive(AVL::Node<T> *recRoot, T val)
{}

template <typename T>
bool AVLTree<T>::isEmpty()
{}

template <typename T>
void AVLTree<T>::print()
{
	if(root == nullptr)
		return;

	postorder(root, 2);
}

template <typename T>
void AVLTree<T>::postorder(AVL::Node<T> *recRoot, int indent)
{
	if(recRoot != NULL) {
		if(recRoot->right) {
			postorder(recRoot->right, indent+4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (recRoot->right)
			std::cout<<" /\n" << std::setw(indent) << ' ';

		std::cout<< recRoot->data << "\n ";

		if(recRoot->left) {
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			postorder(recRoot->left, indent+4);
		}
	}
}

#endif /* TREES_AVLTREE_H_ */

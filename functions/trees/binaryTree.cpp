#ifdef TREES_BINARYTREE_H_

#include "binaryTree.h"
template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T val)
{
	root = new BT::Node<T>(val);
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &rhs)
{
	std::cout << ">>>calling copy constructor (BinaryTree)" << std::endl;
	root = new BT::Node<T>(*(rhs.root));
	recursiveCopy(root, rhs.root);
}

/*template <typename T>
BinaryTree<T>::BinaryTree(BinaryTree<T> &&rhs)
{
	std::cout << ">>>calling move constructor (BinaryTree)" << std::endl;
	root = new BT::Node<T>(std::move(*(rhs.root)));
	//delete rhs.root;
}*/

template <typename T>
BinaryTree<T>::~BinaryTree()
{
	std::cout << ">>>calling destructor (BinaryTree)" << std::endl;
	clear();
}

template <typename T>
const BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree &rhs)
{
	std::cout << ">>>calling copy assignment operator (BinaryTree)" << std::endl;

	if(this != &rhs)
	{
		clear();
		root = new BT::Node<T>(*(rhs.root));
		recursiveCopy(root, rhs.root);
	}

	return *this;
}

/*template <typename T>
const BinaryTree<T> &BinaryTree<T>::operator=(BinaryTree<T> &&rhs)
{
	std::cout << ">>>calling move assignment operator (BinaryTree)" << std::endl;

	if(this != &rhs)
	{
		clear();
		root = new BT::Node<T>(std::move(*(rhs.root)));
		//delete rhs.root;
	}

	return *this;
}*/

template <typename T>
bool BinaryTree<T>::operator==(const BinaryTree &rhs) const
{

}

template <typename T>
void BinaryTree<T>::clear()
{
	if(root == nullptr)
		return;

	clearRecursive(root);
}

template <typename T>
void BinaryTree<T>::clearRecursive(BT::Node<T> *recRoot)
{
	if(recRoot == nullptr)
			return;

	clearRecursive(recRoot -> left);
	clearRecursive(recRoot -> right);
	std::cout << "Removing " << recRoot -> data << std::endl;
	delete recRoot;
	recRoot = nullptr;
}

template <typename T>
void BinaryTree<T>::recursiveCopy(BT::Node<T> *recRoot, BT::Node<T> *rhsRecRoot)
{
	if(rhsRecRoot == nullptr)
		return;
	if(rhsRecRoot -> left != nullptr)
		recRoot -> left = new BT::Node<T>(*(rhsRecRoot -> left));
	if(rhsRecRoot -> right != nullptr)
		recRoot -> right = new BT::Node<T>(*(rhsRecRoot -> right));

	recursiveCopy(recRoot -> left, rhsRecRoot -> left);
	recursiveCopy(recRoot -> right, rhsRecRoot -> right);
	return;
}

template <typename T>
void BinaryTree<T>::recursiveMove(BT::Node<T> *recRoot, BT::Node<T> *rhsRecRoot)
{}

template <typename T>
void BinaryTree<T>::append(T val)
{
	BT::Node<T> *node = new BT::Node<T>(val);

	if(root == nullptr)
		root = node;

	else
		appendRecursive(root, node);
}

template <typename T>
void BinaryTree<T>::appendRecursive(BT::Node<T> *recRoot, BT::Node<T> *node)
{
	if(node -> data < recRoot -> data)
	{
		if(recRoot -> left != nullptr)
			appendRecursive(recRoot -> left, node);
		else
			recRoot -> left = node;
	}

	else if(node -> data > recRoot -> data)
	{
		if(recRoot -> right != nullptr)
			appendRecursive(recRoot -> right, node);
		else
			recRoot -> right = node;
	}
}

template <typename T>
void BinaryTree<T>::remove(T val)
{
	if(root == nullptr)
		return;

	removeRecursive(root, val);
}

template <typename T>
void BinaryTree<T>::removeRecursive(BT::Node<T> *&recRoot, T val)
{
	if(recRoot == nullptr)
		return;

	if(recRoot -> data < val)
		removeRecursive(recRoot -> right, val);

	else if(recRoot -> data > val)
		removeRecursive(recRoot -> left, val);

	// node has no children
	if(recRoot -> data == val && recRoot -> left == nullptr && recRoot -> right == nullptr)
	{
		delete recRoot;
		recRoot = nullptr;
	}

	// node has one child
	else if(recRoot -> data == val && recRoot -> left != nullptr && recRoot -> right == nullptr)
	{
		BT::Node<T> *storeLeft = recRoot -> left;
		*recRoot = *storeLeft;

		delete storeLeft;
		storeLeft = nullptr;
	}
	else if(recRoot -> data == val && recRoot -> left == nullptr && recRoot -> right != nullptr)
	{
		BT::Node<T> *storeRight = recRoot -> right;
		*recRoot = *storeRight;

		delete storeRight;
		storeRight = nullptr;
	}

	//node has two children
	else if(recRoot -> data == val && recRoot -> left != nullptr && recRoot -> right != nullptr)
	{
		BT::Node<T> *&smallestSubNode = getSmallestInRightSubTree(recRoot -> right);
		recRoot -> data = smallestSubNode -> data;
		removeRecursive(recRoot -> right, recRoot -> data);
	}

	return;
}

template <typename T>
BT::Node<T> *&BinaryTree<T>::getSmallestInRightSubTree(BT::Node<T> *recRoot)
{
	if(recRoot -> left != nullptr)
	{
		BT::Node<T> *&ret = getSmallestInRightSubTree(recRoot -> left);
		return ret;
	}

	BT::Node<T> *&ret = recRoot;
	return ret;
}

template <typename T>
void BinaryTree<T>::postorder(BT::Node<T>* p, int indent)
{
	if(p != NULL) {
		if(p->right) {
			postorder(p->right, indent+4);
		}
		if (indent) {
			std::cout << std::setw(indent) << ' ';
		}
		if (p->right)
			std::cout<<" /\n" << std::setw(indent) << ' ';

		std::cout<< p->data << "\n ";

		if(p->left) {
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			postorder(p->left, indent+4);
		}
	}
}

template <typename T>
void BinaryTree<T>::print()
{
	if(root == nullptr)
		return;

	postorder(root, 2);
}

template <typename T>
void BinaryTree<T>::printPreOrder()
{}
template <typename T>
void BinaryTree<T>::printInOrder()
{}
template <typename T>
void BinaryTree<T>::printPostOrder()
{}

#endif /* TREES_BINARYTREE_H_ */



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

	root = new AVL::Node<T>(new AVL::Node<T>(rhs.root));
	recursiveCopy(root, rhs.root);
}

/*template <typename T>
AVLTree<T>::AVLTree(AVLTree<T> &&rhs)
{
	std::cout << ">>>Calling move constructor (AVLTree)" << std::endl;
	root = new AVL::Node<T>(new AVL::Node<T>(std::move(rhs.root)));
	rhs.clear();
}*/

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
		root = new AVL::Node<T>(new AVL::Node<T>(rhs.root));
		recursiveCopy(root, rhs.root);
	}

	return *this;
}

/*template <typename T>
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
}*/

template <typename T>
bool AVLTree<T>::operator==(const AVLTree<T> &rhs) const
{
	if(this == &rhs)
		return true;

	if( (root == nullptr && rhs.root != nullptr) || (root != nullptr && rhs.root == nullptr))
		return false;

	bool retCond = true;
	recursiveCheck(root, rhs.root, retCond);

	return retCond;
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

	clearRecursive(recRoot -> left);
	clearRecursive(recRoot -> right);
	std::cout << "Removing " << recRoot -> data << std::endl;
	delete recRoot;
	recRoot = nullptr;
}

template <typename T>
void AVLTree<T>::recursiveCopy(AVL::Node<T> *recRoot, AVL::Node<T> *rhsRecRoot)
{
	if(rhsRecRoot == nullptr)
		return;
	if(rhsRecRoot -> left != nullptr)
		recRoot -> left = new AVL::Node<T>(*(rhsRecRoot -> left));
	if(rhsRecRoot -> right != nullptr)
		recRoot -> right = new AVL::Node<T>(*(rhsRecRoot -> right));

	recursiveCopy(recRoot -> left, rhsRecRoot -> left);
	recursiveCopy(recRoot -> right, rhsRecRoot -> right);
	return;
}

template <typename T>
void AVLTree<T>::recursiveCheck(const AVL::Node<T> *recRoot, const AVL::Node<T> *rhsRecRoot, bool &retCond) const
{
	if(recRoot == nullptr && rhsRecRoot == nullptr)
		return;

	else if( (recRoot == nullptr && rhsRecRoot != nullptr) || (recRoot != nullptr && rhsRecRoot == nullptr))
		retCond = false;

	else if(recRoot -> data != rhsRecRoot -> data)
		retCond = false;

	if(retCond == true)
		recursiveCheck(recRoot -> left, rhsRecRoot -> left, retCond);

	if(retCond == true)
		recursiveCheck(recRoot -> right, rhsRecRoot -> right, retCond);
}

template <typename T>
void AVLTree<T>::swapNodeVal(AVL::Node<T> *left, AVL::Node<T> *right)
{
	if(left == nullptr || right == nullptr)
		return;

	T store = left -> data;
	left -> data = right -> data;
	right -> data = store;
	return;
}

template <typename T>
int AVLTree<T>::balance(AVL::Node<T> *left, AVL::Node<T> *right)
{
	if(left == nullptr && right == nullptr)
		return 0;

	else if(left != nullptr && right == nullptr)
		return (left -> height - 0);

	else if(left == nullptr && right != nullptr)
		return (0 - right -> height);

	else
		return (left -> height - right -> height);
}

template <typename T>
uint AVLTree<T>::max(AVL::Node<T> *left, AVL::Node<T> *right)
{
	if(left == nullptr && right == nullptr)
		return 0;

	else if(left != nullptr && right == nullptr)
		return left -> height;

	else if(left == nullptr && right != nullptr)
		return right -> height;

	else
	{
		if(left -> height >= right -> height)
			return left -> height;

		else
			return right -> height;
	}
}

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

	if(recRoot -> data > val)
		appendRecursive(recRoot -> left, val, appended);

	else if(recRoot -> data < val)
		appendRecursive(recRoot -> right, val, appended);

	if(appended == false && recRoot -> data > val)
	{
		recRoot -> left = new AVL::Node<T>(val);
		appended = true;
	}

	else if(appended == false && recRoot -> data < val)
	{
		recRoot -> right = new AVL::Node<T>(val);
		appended = true;
	}

	recRoot -> height = 1 + max(recRoot -> left, recRoot -> right);

	// balance = left - right
	int nodeBalance = balance(recRoot -> left, recRoot -> right);

	// left >> right
	if(nodeBalance > 1)
	{
		// left left
		if(val < recRoot -> left -> data)
		{
			std::cout << ">>>left-left rotation (AVLTree)" << std::endl;
			leftRotate(recRoot);
		}

		// left right
		else if(val > recRoot -> left -> data)
		{
			std::cout << ">>>left-right rotation (AVLTree)" << std::endl;
			leftRightRotate(recRoot);
		}
	}

	// left << right
	if(nodeBalance < -1)
	{
		// right right
		if(val > recRoot -> right -> data)
		{
			std::cout << ">>>right-right rotation (AVLTree)" << std::endl;
			rightRotate(recRoot);
		}

		// right left
		else if(val < recRoot -> right -> data)
		{
			std::cout << ">>>right-left rotation (AVLTree)" << std::endl;
			rightLeftRotate(recRoot);
		}
	}
}

template <typename T>
void AVLTree<T>::leftRotate(AVL::Node<T> *nodeA)
{
	AVL::Node<T> *nodeB = nodeA -> left;
	AVL::Node<T> *nodeC = nodeB -> left;
	AVL::Node<T> *T3 = nodeB -> right;
	AVL::Node<T> *T4 = nodeA -> right;

	swapNodeVal(nodeA, nodeB);

	nodeA -> left = nodeC;
	nodeA -> right = nodeB;
	nodeB -> left = T3;
	nodeB -> right = T4;

	nodeC -> height = 1 + max(nodeC -> left, nodeC -> right);
	nodeB -> height = 1 + max(nodeB -> left, nodeB -> right);
	nodeA -> height = 1 + max(nodeA -> left, nodeA -> right);
}

template <typename T>
void AVLTree<T>::leftRightRotate(AVL::Node<T> *nodeA)
{
	AVL::Node<T> *nodeB = nodeA -> left;
	AVL::Node<T> *nodeC = nodeB -> right;
	AVL::Node<T> *T1 = nodeB -> left;
	AVL::Node<T> *T2 = nodeC -> left;
	AVL::Node<T> *T3 = nodeC -> right;

	swapNodeVal(nodeB, nodeC);

	nodeB -> left = nodeC;
	nodeB -> right = T3;
	nodeC -> left = T1;
	nodeC -> right = T2;

	nodeC -> height = 1 + max(nodeC -> left, nodeC -> right);
	nodeB -> height = 1 + max(nodeB -> left, nodeB -> right);
	nodeA -> height = 1 + max(nodeA -> left, nodeA -> right);

	leftRotate(nodeA);
}

template <typename T>
void AVLTree<T>::rightRotate(AVL::Node<T> *nodeA)
{
	AVL::Node<T> *nodeB = nodeA -> right;
	AVL::Node<T> *nodeC = nodeB -> right;
	AVL::Node<T> *T1 = nodeA -> left;
	AVL::Node<T> *T2 = nodeB -> left;

	swapNodeVal(nodeA, nodeB);

	nodeA -> left = nodeB;
	nodeA -> right = nodeC;
	nodeB -> left = T1;
	nodeB -> right = T2;

	nodeC -> height = 1 + max(nodeC -> left, nodeC -> right);
	nodeB -> height = 1 + max(nodeB -> left, nodeB -> right);
	nodeA -> height = 1 + max(nodeA -> left, nodeA -> right);
}

template <typename T>
void AVLTree<T>::rightLeftRotate(AVL::Node<T> *nodeA)
{
	AVL::Node<T> *nodeB = nodeA -> right;
	AVL::Node<T> *nodeC = nodeB -> left;
	AVL::Node<T> *T2 = nodeC -> left;
	AVL::Node<T> *T3 = nodeC -> right;
	AVL::Node<T> *T4 = nodeB -> right;

	swapNodeVal(nodeB, nodeC);

	nodeB -> left = T2;
	nodeB -> right = nodeC;
	nodeC -> left = T3;
	nodeC -> right = T4;

	nodeC -> height = 1 + max(nodeC -> left, nodeC -> right);
	nodeB -> height = 1 + max(nodeB -> left, nodeB -> right);
	nodeA -> height = 1 + max(nodeA -> left, nodeA -> right);

	rightRotate(nodeA);
}

template <typename T>
void AVLTree<T>::remove(T val)
{
	if(root == nullptr)
	{
		return;
	}

	removeRecursive(root, val);
}

template <typename T>
void AVLTree<T>::removeRecursive(AVL::Node<T> *&recRoot, T val)
{
	if(recRoot == nullptr)
		return;

	if(recRoot -> data > val)
		removeRecursive(recRoot -> left, val);

	else if(recRoot -> data < val)
		removeRecursive(recRoot -> right, val);

	// node has no children
	if(recRoot -> data == val && recRoot -> left == nullptr && recRoot -> right == nullptr)
	{
		delete recRoot;
		recRoot = nullptr;
	}

	// node has one child
	else if(recRoot -> data == val && recRoot -> left != nullptr && recRoot -> right == nullptr)
	{
		AVL::Node<T> *storeLeft = recRoot -> left;
		*recRoot = *storeLeft;

		delete storeLeft;
		storeLeft = nullptr;
	}
	else if(recRoot -> data == val && recRoot -> left == nullptr && recRoot -> right != nullptr)
	{
		AVL::Node<T> *storeRight = recRoot -> right;
		*recRoot = *storeRight;

		delete storeRight;
		storeRight = nullptr;
	}

	//node has two children
	else if(recRoot -> data == val && recRoot -> left != nullptr && recRoot -> right != nullptr)
	{
		AVL::Node<T> *&smallestSubNode = getSmallestInRightSubTree(recRoot -> right);
		recRoot -> data = smallestSubNode -> data;
		removeRecursive(recRoot -> right, recRoot -> data);
	}

	if(recRoot != nullptr)
	{
		recRoot -> height = 1 + max(recRoot -> left, recRoot -> right);

		// balance = left - right
		int nodeBalance = balance(recRoot -> left, recRoot -> right);

		// left >> right
		if(nodeBalance > 1)
		{
			// left left
			if(balance(recRoot -> left -> left, recRoot -> left -> right) >= 0)
			{
				std::cout << ">>>left-left rotation (AVLTree)" << std::endl;
				leftRotate(recRoot);
			}

			// left right
			else if(balance(recRoot -> left -> left, recRoot -> left -> right) < 0)
			{
				std::cout << ">>>left-right rotation (AVLTree)" << std::endl;
				leftRightRotate(recRoot);
			}
		}

		// left << right
		if(nodeBalance < -1)
		{
			// right right
			if(balance(recRoot -> right -> left, recRoot -> right -> right) <= 0)
			{
				std::cout << ">>>right-right rotation (AVLTree)" << std::endl;
				rightRotate(recRoot);
			}

			// right left
			else if(balance(recRoot -> right -> left, recRoot -> right -> right) > 0)
			{
				std::cout << ">>>right-left rotation (AVLTree)" << std::endl;
				rightLeftRotate(recRoot);
			}
		}
	}

	return;
}

template <typename T>
AVL::Node<T> *&AVLTree<T>::getSmallestInRightSubTree(AVL::Node<T> *recRoot)
{
	if(recRoot -> left != nullptr)
	{
		AVL::Node<T> *&ret = getSmallestInRightSubTree(recRoot -> left);
		return ret;
	}

	AVL::Node<T> *&ret = recRoot;
	return ret;
}

template <typename T>
bool AVLTree<T>::find(T val)
{
	if(root == nullptr)
		return false;

	bool retCond = false;
	findRecursive(root, val, retCond);

	return retCond;
}

template <typename T>
void AVLTree<T>::findRecursive(AVL::Node<T> *recRoot, T val, bool &retCond)
{
	if(recRoot == nullptr)
		return;

	if(recRoot -> data == val)
		retCond = true;

	if(recRoot -> left != nullptr && retCond == false)
		findRecursive(recRoot -> left, val, retCond);

	if(recRoot -> right != nullptr && retCond == false)
		findRecursive(recRoot -> right, val, retCond);
}

template <typename T>
bool AVLTree<T>::isEmpty()
{
	if(root == nullptr)
		return true;

	else
		return false;
}

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

		std::cout<< recRoot->data << "," << recRoot->height << "\n ";

		if(recRoot->left) {
			std::cout << std::setw(indent) << ' ' <<" \\\n";
			postorder(recRoot->left, indent+4);
		}
	}
}

#endif /* TREES_AVLTREE_H_ */

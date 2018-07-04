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
	if(this == &rhs)
		return true;

	if( (root == nullptr && rhs.root != nullptr) || (root != nullptr && rhs.root == nullptr))
		return false;

	bool retCond = true;
	recursiveCheck(root, rhs.root, retCond);

	return retCond;
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
void BinaryTree<T>::recursiveCheck(const BT::Node<T> *recRoot, const BT::Node<T> *rhsRecRoot, bool &retCond) const
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
bool BinaryTree<T>::find(T val)
{
	if(root == nullptr)
		return false;

	bool retCond = false;
	findRecursive(root, val, retCond);

	return retCond;
}

template <typename T>
void BinaryTree<T>::findRecursive(BT::Node<T> *recRoot, T val, bool &retCond)
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
bool BinaryTree<T>::isEmpty()
{
	if(root == nullptr)
		return true;

	else
		return false;
}

template <typename T>
void BinaryTree<T>::print()
{
	if(root == nullptr)
		return;

	postorder(root, 2);
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

// extra functions
template <typename T>
BinaryTree<T> BinaryTree<T>::arrayToTree(std::vector<T> arr)
{
	if(arr.size() == 0)
		return *this;
	if(arr.size() == 1)
	{
		this -> append(arr[0]);
		return *this;
	}

	arrayToTree(arr, 0, arr.size() - 1);

	return *this;
}

template <typename T>
void BinaryTree<T>::arrayToTree(std::vector<T> arr, int startId, int endIdx)
{
	if(endIdx < startId)
		return;

	int midIdx = (endIdx + startId) / 2;

	this -> append(arr[midIdx]);

	arrayToTree(arr, startId, midIdx - 1);
	arrayToTree(arr, midIdx + 1, endIdx);
}

template <typename T>
std::vector<LinkedList<uint> *> BinaryTree<T>::depthListsPreOrder()
{
	std::vector<LinkedList<uint> *> ret;
	depthListsPreOrder(this -> root, ret, 0);
	return ret;
}

template <typename T>
void BinaryTree<T>::depthListsPreOrder(BT::Node<T> *recRoot, std::vector<LinkedList<uint> *> &vec, uint level)
{
	if(recRoot == nullptr)
		return;

	LinkedList<uint> *currLevelList;

	if(vec.size() == level)
	{
		currLevelList = new LinkedList<T>;
		vec.push_back(currLevelList);
	}

	else
		currLevelList = vec[level];

	currLevelList->append(recRoot -> data);
	depthListsPreOrder(recRoot -> left, vec, level + 1);
	depthListsPreOrder(recRoot -> right, vec, level + 1);
}

template <typename T>
std::vector<LinkedList<uint> *> BinaryTree<T>::depthListsBFS()
{
	std::vector<LinkedList<uint> *> ret;

	if(root == nullptr)
		return ret;

	LinkedList<T> *childList = new LinkedList<T>(root -> data);
	LinkedList<BT::Node<T>*> childNodeList(root);
	LinkedList<BT::Node<T>*> parentNodeList;
	LL::Node<BT::Node<T>*> *itr;

	while(childNodeList.getSize() > 0)
	{
		ret.push_back(childList);
		parentNodeList = childNodeList;
		childNodeList.clear();
		childList = new LinkedList<T>;

		itr = parentNodeList.returnHead();
		while(itr != nullptr)
		{
			if(itr -> data -> left != nullptr)
			{
				childNodeList.append(itr -> data -> left);
				childList -> append(itr -> data -> left -> data);
			}

			if(itr -> data -> right != nullptr)
			{
				childNodeList.append(itr -> data -> right);
				childList -> append(itr -> data -> right -> data);
			}

			itr = itr -> next;
		}
	}

	return ret;
}

template <typename T>
bool BinaryTree<T>::checkBalanced()
{
	if(root == nullptr)
		return true;

	bool ret = true;
	checkBalanced(root, 0, ret);
	return ret;
}

template <typename T>
int BinaryTree<T>::checkBalanced(BT::Node<T> *recRoot, int depth, bool &isBalanced)
{
	if(isBalanced == false)
		return -1;
	else if(recRoot == nullptr)
		return (depth - 1);

	int leftHeight = checkBalanced(recRoot -> left, depth + 1, isBalanced);
	int rightHeight = checkBalanced(recRoot -> right, depth + 1, isBalanced);

	// check balance
	int balance = (leftHeight - rightHeight);
	if(balance < -1 || balance > 1)
		isBalanced = false;

	// return max
	if(leftHeight > rightHeight)
		return leftHeight;

	else
		return rightHeight;
}

#endif /* TREES_BINARYTREE_H_ */



#ifdef TREES_BINARYTREE_H_

#include "binaryTree.h"

										/***************************
										 *** Class Functionality ***
										 ***************************/

template <typename T>
BinaryTree<T>::BinaryTree()
{
	root = nullptr;
	size = 0;
}

template <typename T>
BinaryTree<T>::BinaryTree(T val)
{
	root = new BT::Node<T>(val);
	size = 1;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &rhs)
{
	std::cout << ">>>calling copy constructor (BinaryTree)" << std::endl;
	root = new BT::Node<T>(*(rhs.root));
	recursiveCopy(root, rhs.root);
	size = rhs.size;
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
		size = rhs.size;
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

										/******************************
										 *** BST Core Functionality ***
										 ******************************/

template <typename T>
void BinaryTree<T>::clear()
{
	if(root == nullptr)
		return;

	clearRecursive(root);
	size = 0;
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

	size++;
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
	size--;
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
	if(size > 0)
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

template <typename T>
void BinaryTree<T>::printPreOrderList()
{
	if(root == nullptr)
			return;

	printPreOrderList(root);

	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printPreOrderList(BT::Node<T>* recRoot)
{
	if(recRoot == nullptr)
		return;

	std::cout << recRoot -> data << " ";
	printPreOrderList(recRoot -> left);
	printPreOrderList(recRoot -> right);
}

template <typename T>
void BinaryTree<T>::printInOrderList()
{
	if(root == nullptr)
			return;

	printInOrderList(root);

	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printInOrderList(BT::Node<T>* recRoot)
{
	if(recRoot == nullptr)
		return;

	printInOrderList(recRoot -> left);

	std::cout << recRoot -> data << " ";

	printInOrderList(recRoot -> right);
}

template <typename T>
void BinaryTree<T>::printPostOrderList()
{
	if(root == nullptr)
			return;

	printPostOrderList(root);

	std::cout << std::endl;
}

template <typename T>
void BinaryTree<T>::printPostOrderList(BT::Node<T>* recRoot)
{
	if(recRoot == nullptr)
		return;

	printPostOrderList(recRoot -> left);
	printPostOrderList(recRoot -> right);
	std::cout << recRoot -> data << " ";
}

template <typename T>
BT::Node<T>* BinaryTree<T>::getRoot()
{
	return root;
}

template <typename T>
uint BinaryTree<T>::getSize()
{
	return size;
}

										/**************************************
										 *** Practice Problem Functionality ***
										 **************************************/

/*********************
 *** Array To Tree ***
 *********************/
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

/**********************************
 *** List Of Depths - Recursive ***
 **********************************/
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

/****************************
 *** List Of Depths - BFS ***
 ****************************/
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

/*********************
 *** Check Balance ***
 *********************/
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

/********************
 *** Is Valid BST ***
 ********************/
template <typename T>
bool BinaryTree<T>::isBST()
{
	if(root == nullptr)
		return true;

	std::vector<T> vec;
	isBST(root, vec);

	bool cond = true;
	for(uint i = 0 ; i < (vec.size() - 1) ; i++)
	{
		if(vec[i] > vec[i + 1])
		{
			cond = false;
			break;
		}
	}

	return cond;
}

template <typename T>
void BinaryTree<T>::isBST(BT::Node<T> *recRoot, std::vector<T> &vec)
{
	if(recRoot == nullptr)
		return;

	isBST(recRoot -> left, vec);
	vec.push_back(recRoot -> data);
	isBST(recRoot -> right, vec);
}

/***********************
 *** Check Successor ***
 ***********************/
template <typename T>
T BinaryTree<T>::inOrderSuccessor(T val)
{
	if(root == nullptr)
		return true;

	bool found = false;
	bool endRec = false;
	T retVal = -1;
	inOrderSuccessor(root, val, retVal, found, endRec);

	return retVal;
}

template <typename T>
void BinaryTree<T>::inOrderSuccessor(BT::Node<T> *recRoot, T val, T &retVal, bool &found, bool &endRec)
{
	if(recRoot == nullptr || endRec == true)
		return;

	inOrderSuccessor(recRoot -> left, val, retVal, found, endRec);

	if(found == true && endRec == false)
	{
		endRec = true;
		retVal = recRoot -> data;
		return;
	}

	if(recRoot -> data == val)
		found = true;

	inOrderSuccessor(recRoot -> right,  val, retVal, found, endRec);
}

/*******************
 *** Build Order ***
 *******************/
template <typename T>
std::vector< std::vector<T> > BinaryTree<T>::buildAdjMatrix(std::vector<T> nodes, std::vector<std::pair<T, T>>  dep)
{
	std::vector< std::vector<T> > ret;
	std::vector<T> sublist;

	for(auto i : nodes)
	{
		sublist.clear();

		for(auto j : dep)
		{
			if(j.second == i)
			{
				sublist.push_back(j.first);
			}
		}

		ret.push_back(sublist);
	}

	return ret;
}

template <typename T>
std::vector<T> BinaryTree<T>::buildOrder(std::vector<T> nodes, std::vector<std::pair<T, T>> dependencies)
{
	std::vector< std::vector<T> > adjMat = buildAdjMatrix(nodes, dependencies);

	uint count = 0;
	for(auto i : adjMat)
	{
		std::cout << count << ":";
		for(auto j : i)
		{
			std::cout << j << " ";
		}
		std::cout << std::endl;
		count++;
	}

	std::vector<T> ret = buildOrder(nodes, adjMat);
	return ret;
}

template <typename T>
std::vector<T> BinaryTree<T>::buildOrder(std::vector<T> nodes, std::vector< std::vector<T> > adjMat)
{
	Stack<T> st;
	std::vector<bool> seenList;
	std::vector<T> ret;

	// initialize everything node position to “not seen”
	for(auto i : nodes)
		seenList.push_back(false);

	// initialize the stack with values that don’t have dependencies
	for(uint i = 0 ; i < adjMat.size() ; i++)
	{
		if(adjMat[i].size() == 0)
		{
			seenList[i] = true;
			st.push(nodes[i]);
			break;
		}
	}

	// now for the fun part of iterative DFS
	T currNode;
	bool canBuild;

	while(!st.isEmpty())
	{
		currNode = st.pop();
		ret.push_back(currNode);

		// for each node
		for(uint i = 0 ; i < adjMat.size() ; i++)
		{

			canBuild = true;
			// for each edge of a particular node
			for(uint j = 0 ; j < adjMat[i].size() ; j++)
			{
				if(seenList[adjMat[i][j]] == false)
				{
					canBuild = false;
					break;
				}
			}

			if(canBuild == true && seenList[i] == false)
			{
				seenList[i] = true;
				st.push(nodes[i]);
				break;
			}
		}
	}

	return ret;
}

/*****************************
 *** First Common Ancestor ***
 *****************************/
template <typename T>
T BinaryTree<T>::firstCommonAncestor(T a, T b)
{
	if(root == nullptr)
		return -1;

	PathStruct pathA, pathB, filler;

	pathA = mapPath(root, a, filler);
	pathB = mapPath(root, b, filler);

	uint minCount = pathA.count < pathB.count ? pathA.count : pathB.count;

	std::cout << "\nPathA" << std::endl;
	for(uint i = 0 ; i < pathA.count ; i++)
	{
		std::cout << ( pathA.path & (0x0001 << i) ) << " ";
	}

	std::cout << "\nPathB" << std::endl;

	for(uint i = 0 ; i < pathB.count ; i++)
	{
		std::cout << ( pathB.path & (0x0001 << i) ) << " ";
	}

	std::cout << std::endl;

	for(uint i = 0 ; i < minCount ; i++)
	{
		uint valA = pathA.path & (0x0001 << i);
		uint valB = pathB.path & (0x0001 << i);
		if(valA == valB)
		{
			filler.path += pathA.path & (0x0001 << i);
			filler.count++;
		}

		else if(valA != valB && i == 0)
		{
			filler.path += pathA.path & (0x0001 << i);
			break;
		}

		else
			break;
	}

	uint count = 0;
	return getValFromPath(root, filler, count);
}

template <typename T>
PathStruct BinaryTree<T>::mapPath(BT::Node<T> *recRoot, T val, PathStruct recPath)
{
	if(recRoot -> data == val)
	{
		recPath.found = true;
		return recPath;
	}

	if(recRoot -> left != nullptr)
	{
		recPath.path += (0 << recPath.count);
		recPath.count++;
		PathStruct ret = mapPath(recRoot -> left, val, recPath);

		if(ret.found)
			return ret;
	}

	if(recRoot -> right != nullptr)
	{
		if(recRoot -> left != nullptr)
			recPath.count--;

		recPath.path += (1 << recPath.count);
		recPath.count++;
		PathStruct ret = mapPath(recRoot -> right, val, recPath);

		if(ret.found)
			return ret;
	}
	return recPath;
}

template <typename T>
T BinaryTree<T>::getValFromPath(BT::Node<T> *recRoot, PathStruct recPath, uint &currCount)
{
	if(currCount == recPath.count)
		return recRoot -> data;

	if( (recPath.path & (1 << currCount) ) == 0)
	{
		currCount++;
		return getValFromPath(recRoot -> left, recPath, currCount);
	}

	else if( (recPath.path & (1 << currCount) ) != 0)
	{
		currCount++;
		return getValFromPath(recRoot -> right, recPath, currCount);
	}
}

/*********************
 *** BST to Arrays ***
 *********************/
template <typename T>
std::vector< std::vector<T> > BinaryTree<T>::BstToArrayPermutations()
{
	std::vector< std::vector<T> > ret;

	if(root == nullptr)
		return ret;

	std::vector< BT::Node<T>* > nodes;
	std::vector<T> recList;
	BstToArrayPermutations(root, nodes, ret, recList);

	return ret;
}

template <typename T>
void BinaryTree<T>::BstToArrayPermutations(BT::Node<T> *recRoot, std::vector< BT::Node<T>* > nodes, std::vector< std::vector<T> > &vec, std::vector<T> recList)
{
	if(recRoot == nullptr)
		return;

	recList.push_back(recRoot -> data);

	if(recRoot -> left != nullptr)
		nodes.push_back(recRoot -> left);
	if(recRoot -> right != nullptr)
		nodes.push_back(recRoot -> right);
	std::vector< BT::Node<T>* > recNodes;

	for(uint i = 0 ; i < nodes.size() ; i++)
	{
		recNodes = nodes;
		recNodes.erase( recNodes.begin() + i );
		BstToArrayPermutations(nodes[i], recNodes, vec, recList);
	}

	if(recList.size() == this -> size)
		vec.push_back(recList);

}

#endif /* TREES_BINARYTREE_H_ */



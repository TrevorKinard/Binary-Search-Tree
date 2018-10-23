#ifndef _Binary_Search_Tree_
#define _Binary_Search_Tree_

template <class DataType>
class BST
{
private:
	//Node Structure
	struct Node
	{
		DataType data;
		Node* leftNode;
		Node* rightNode;
	};
public:
	//Constructor
	BST()
	{
		//Set the root of the binary search tree
		root = nullptr;
	}
	//Destructor
	~BST()
	{
		//Delete low nodes from child to parent
		//then delete high nodes from child to parent
	}

	//Add data to the binary search tree
	void insert(DataType iData)
	{
		//If no nodes in tree create node a root
		if (root == nullptr)
		{
			root = new Node{ iData, nullptr, nullptr };
			return;
		}
		Node* current = root;
		while (true)
		{
			//If node already exists return
			if (current->data == iData) return;
			//If data is lesser than current node compare to the lesser values
			if (iData < current->data)
			{
				//If nothing left to compare to insert the data
				if (current->leftNode == nullptr)
				{
					current->leftNode = new Node{ iData, nullptr, nullptr };
					return;
				}
				//go to left node for comparison
				current = current->leftNode;
			}
			//If data is greater than current node compare to the greater values
			else
			{
				//If nothing left to compare to insert the data
				if (current->rightNode == nullptr)
				{
					current->rightNode = new Node{ iData, nullptr, nullptr };
					return;
				}
				//Go to right node for comparison
				current = current->rightNode;
			}
		}
	}
	//Remove Node at desired position - Need to have replace equal current's parent child node
	void remove(DataType iData)
	{
		//Set current to found node
		Node* current = find(iData);;

		Node* temp = current;
		//If left child exists find replacement node
		if (current->leftNode != nullptr)
		{
			//Node that will replace current
			Node* replace = current->leftNode;
			//Find the highest node in left child
			while (replace->rightNode->rightNode != nullptr)
			{
				replace = replace->rightNode->rightNode;
			}
			current = replace;
			//Set replace's previous parent's child connection to null
			replace->rightNode = nullptr;
			//Set replacement children to current's
			replace->rightNode = temp->rightNode;
			replace->leftNode = temp->leftNode;
		}
		//Go down right child to find replacement node
		else
		{
			//Node that will replace current
			Node* replace = current->rightNode;
			//Find the lowest node in right child
			while (replace->leftNode->leftNode != nullptr)
			{
				replace = replace->leftNode->leftNode;
			}
			current = replace;
			//Set replace's previous parent's child connection to null
			replace->leftNode = nullptr;
			//Set replacement children to current's
			replace->rightNode = temp->rightNode;
			replace->leftNode = temp->leftNode;
		}
		delete temp;
		return;
	}
	//Return maximum valued node
	Node* maximum()
	{
		Node* current = root;
		while (root != nullptr)
		{
			if (current->rightNode == nullptr) return current;
			current = current->rightNode;
		}
	}
	//Find node with datatype
	Node* find(DataType iData)
	{
		//If no nodes in tree create node a root
		if (root == nullptr)
		{
			return nullptr;
		}
		Node* current = root;
		while (current != nullptr)
		{
			//If node already exists return
			if (current->data == iData) return current;
			//If data is lesser than current node compare to the lesser values
			if (iData < current->data)
			{
				//go to left node for comparison
				current = current->leftNode;
			}
			//If data is greater than current node compare to the greater values
			else
			{
				//Go to right node for comparison
				current = current->rightNode;
			}
		}
	}
	//Display node at ordered position
	Node* display(unsigned int iter)
	{
		//lowest node acts as 0
		//Each node higher than that in order is its position
	}

private:
	Node* root;
};
#endif
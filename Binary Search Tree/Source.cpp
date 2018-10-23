#include <iostream>
#include <string>
#include "BinarySearchTree.h"

void main()
{
	//User  number input
	int input = 0;
	//Create Linked List
	BST<int> created = BST<int>();

	while (input != 999)
	{
		//Clear screen
		system("cls");
		//Menu display
		std::cout << "1: Add node\n2: Delete Node\n3: Maximum value\n4: Find value\n999: Exit\n";

		//Grab user's input
		std::cin >> input;
		//Switch through user's choice
		switch (input)
		{
		case 1:
			std::cout << "Input desired value: ";
			std::cin >> input;
			created.insert(input);
			input = 0;
			break;
		case 2:
			std::cout << "Input desired value: ";
			std::cin >> input;
			created.remove(input);
			input = 0;
			break;
		case 3:
			std::cout << "Maximum value is " << created.maximum()->data << "\n";
			break;
		case 4:
			std::cout << "Input desired value: ";
			std::cin >> input;
			created.find(input);
			input = 0;
			break;
		}
		system("pause");
	}
}
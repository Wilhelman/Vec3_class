#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <assert.h>
#include <iostream>

template<class TYPE>
class LinkedList {

private:

	struct node {
		TYPE value;
		node* previous;
		node* next;
	};

	node* first;

public:

	LinkedList() {
		first = NULL;
	}

	~LinkedList() {
		while (first != NULL)
		{
			node* aux = first;
			first = first->next;
			delete aux;
		}
	}

	void pushBack(TYPE value)
	{
		node* aux = new node;
		aux->value = value;
		aux->next = NULL;

		if (first == NULL)
		{
			aux->previous = NULL;
			first = aux;
		}
		else
		{
			node* iterator = first;
			while (iterator->next != NULL)
				iterator = iterator->next;

			aux->previous = iterator;
			iterator->next = aux;
		}
	}

	int getNumNodes() const {
		node* iterator = first;
		int numNodes = 0;

		if (first != NULL) {
			numNodes++;
			while (iterator->next != NULL) {
				iterator = iterator->next;
				numNodes++;
			}
		}

		return numNodes;
	}

	void printNodes() const
	{
		if (first == NULL)
		{
			std::cout << "No values to show bruh" << std::endl;
		}
		else
		{

			std::cout << "Showing the values stored in the linked list..." << std::endl;

			std::cout << std::endl;

			node* iterator = first;
			while (iterator != NULL)
			{
				if (iterator->previous == NULL)
					std::cout << "<-| NULL | ";
				else
					std::cout << "<-| @node " << iterator->previous->value << " | ";

				std::cout << iterator->value;

				if (iterator->next == NULL)
					std::cout << " | NULL |->\n";
				else
					std::cout << " | @node " << iterator->next->value << " |->" << std::endl;

				iterator = iterator->next;
			}

			std::cout << std::endl;
		}
	}

	/*void changeStorageMethodToDynArray(DynArray<int>* dynArr) {

		node* iterator = first;
		int index = 0;
		if (first != NULL) {
			dynArr->insert(index++, iterator->value);
			while (iterator->next != NULL) {
				iterator = iterator->next;
				dynArr->insert(index++, iterator->value);
			}
		}

	}*/

	/*void changeStorageMethodToLinkedList(DynArray<int>* dynArr, vec3* vectorTest) {

		//no controls.. yolo
		while (first != NULL)
		{
			node* aux = first;
			first = first->next;
			delete aux;
		}

		for (int i = 0; i < dynArr->size(); i++)
		{
			vectorTest->pushBack((*dynArr)[i]);
		}

	}
	*/

};

#endif
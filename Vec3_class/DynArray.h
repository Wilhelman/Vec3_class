#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <assert.h>
#include <iostream>

#define min(a, b) (a < b) ? a : b

#define MIN_ARRAY_BLOCK_SIZE 10

template <class Type>
class DynArray {
public:
	DynArray();
	DynArray(unsigned int memSize);
	~DynArray();

	bool empty() const;
	unsigned int size() const;

	bool insert(unsigned int index, const Type& elem);
	bool remove(unsigned int index);

	Type& operator[] (unsigned int index) const;
	void shrinkToFit();

	void print() const;

private:
	void allocMem(unsigned int memSize);

	Type* arrayElems;
	unsigned int memSize;
	unsigned int numElems;
};

template <class Type>
DynArray<Type>::DynArray()
{
	this->memSize = MIN_ARRAY_BLOCK_SIZE;
	this->numElems = 0;
	allocMem(this->memSize);
}

template <class Type>
DynArray<Type>::DynArray(unsigned int memSize)
{
	this->memSize = memSize;
	this->numElems = 0;
	allocMem(this->memSize);
}

template <class Type>
DynArray<Type>::~DynArray()
{
	if (arrayElems != NULL)
	{
		delete[] arrayElems;
		arrayElems = NULL;
	}
}

template <class Type>
bool DynArray<Type>::empty() const
{
	return numElems == 0;
}

template <class Type>
unsigned int DynArray<Type>::size() const
{
	return numElems;
}

template <class Type>
bool DynArray<Type>::insert(unsigned int index, const Type& elem)
{
	if (index > numElems)
		return false;

	if (index == numElems - 1)
	{
		if (numElems >= memSize)
		{
			allocMem(memSize + MIN_ARRAY_BLOCK_SIZE);
		}

		arrayElems[numElems] = arrayElems[index];
		arrayElems[index] = elem;
		numElems++;
		return true;
	}

	if (index == numElems)
	{
		allocMem(memSize + MIN_ARRAY_BLOCK_SIZE);
	}

	for (int i = numElems; i > index; --i)
	{
		arrayElems[i] = arrayElems[i - 1];
	}

	arrayElems[index] = elem;
	numElems++;
	return true;
}

template <class Type>
bool DynArray<Type>::remove(unsigned int index)
{
	if (index < numElems)
	{
		for (int i = index; i < numElems - 1; ++i)
		{
			arrayElems[i] = arrayElems[i + 1];
		}
		numElems--;
		return true;
	}
	else
	{
		return false;
	}
}

template <class Type>
Type& DynArray<Type>::operator[] (unsigned int index) const
{
	assert(index < numElems);
	return arrayElems[index];
}

template <class Type>
void DynArray<Type>::shrinkToFit()
{
	if (numElems < memSize)
		allocMem(numElems);
}

template <class Type>
void DynArray<Type>::print() const
{
	if (numElems == 0)
	{
		std::cout << "Dynamic array empty" << std::endl;
	}
	else
	{
		for (int i = 0; i < numElems; ++i)
			std::cout << arrayElems[i] << " " << std::endl;

		std::cout << std::endl;
	}
}

template <class Type>
void DynArray<Type>::allocMem(unsigned int memSize)
{
	Type* aux = arrayElems;
	this->arrayElems = new Type[memSize];

	this->memSize = memSize;
	this->numElems = min(this->numElems, this->memSize);

	for (int i = 0; i < this->numElems; ++i)
		this->arrayElems[i] = aux[i];

	// Delete aux
	if (aux != NULL)
		delete[] aux;
}

#endif


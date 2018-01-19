#pragma once

#include <cstring>


#ifndef RENDERINGOBJECTS_HPP
#define RENDERINGOBJECTS_HPP

template<class object>
class RenderingObjects {
public:
	RenderingObjects();
	RenderingObjects(const RenderingObjects &a); // copy
	~RenderingObjects();
	RenderingObjects& operator = (const RenderingObjects &a); // assigment operator

	object& operator [] (unsigned int index); // get array item
	void Add(const object &item); // Add item to the end of array.

	unsigned int GetSize(); // get number of elements
	void SetSize(unsigned int newSize);
	void Clear(); // clears array memory
	void Delete(unsigned int pos); // delete array item.
	void *getptr(); // get void* pointer to array data.
	
	enum exception { MEMFAIL }; // change over to new file.
	void DrawShape(int x) { (this->array[x]).Draw(); } // if it's not a pointer.
	//void Update(int x) { ((int*)this->array[x])(); }
private:
	object *array; // pointer for array's memory
	unsigned int size; // size of array (elements)
	unsigned int realSize; // size of allocated memory

	const static int rendering_objects_step = 128; // initial size of array memory.
	const static int rendering_objects_mult = 2; // multiplier
};

////////////////////////////////////////////////////////////////////

template<class object>
RenderingObjects<object>::RenderingObjects() {
	realSize = rendering_objects_step;

	size = 0;
	array = (object*)malloc(realSize * sizeof(object));

	if (array == NULL)
		throw MEMFAIL;
}

template<class object>
RenderingObjects<object>::~RenderingObjects() {
	if (array) {
		free(array);
		array = NULL;
	}
}

template<class object>
RenderingObjects<object>::RenderingObjects(const RenderingObjects &a) {
	array = (object*)malloc(sizeof(object)*a.realSize);
	if (array == NULL)
		throw MEMFAIL;

	memcpy(array, a.array, sizeof(object)*a.realSize);
	realSize = a.realSize;
	size = a.size;
}

template<class object>
RenderingObjects<object>& RenderingObjects<object>::operator= (const RenderingObjects &a) {
	if (this == &a)
		return *this;
	if (a.size == 0)
		Clear();

	SetSize(a.size);
	memcpy(array, a.array, sizeof(object)*a.size);

	return *this;
}

template<class object>
unsigned int RenderingObjects<object>::GetSize() {
	return size;
}

template<class object>
void RenderingObjects<object>::SetSize(unsigned int newSize) {
	size = newSize;

	if (size != 0) {
		// change array memory size if new size
		// is larger than current or new size
		// is less than half of the current
		if ((size > realSize) || (size < realSize / 2)) {
			realSize = size;
			array = (object*)realloc(array, sizeof(object)*size);
			if (array == NULL)
				throw MEMFAIL;
		}
	} else {
		Clear();
	}
}

template<class object>
void RenderingObjects<object>::Delete(unsigned int pos) {
	if (size == 1) // if the array only has 1 element.
		Clear();
	else {
		// otherwise shift array elements
		for (unsigned int i = pos; i < size - 1; i++)
			array[i] = array[i + 1];

		size--;
	}
}

template<class object>
void RenderingObjects<object>::Clear() {
	size = 0;
	array = (object*)realloc(array, sizeof(object)*rendering_objects_step); // set initial size again.
	realSize = rendering_objects_step;
}

template<class object>
void *RenderingObjects<object>::getptr() {
	return array;
}

template<class object>
object& RenderingObjects<object>::operator[] (unsigned int index) {
	return array(index);
}

template <class object>
void RenderingObjects<object>::Add(const object &item) {
	size++;

	if (size > realSize) {
		realSize *= rendering_objects_mult;
		array = (object*)realloc(array, sizeof(object)*realSize);

		if (array == NULL)
			throw MEMFAIL;
	}

	array[size - 1] = item;
}



#endif //!RENDERINGOBJECTS_HPP
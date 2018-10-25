// tVector.h
#pragma once

template <typename T>
class TVECTOR
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	TVECTOR()// initializes the vector's default values
	{
		arr = new T[0]();
		arrSize = 0;
		arrCapacity = 0;
	}
	~TVECTOR()                         // destroys the underlying array
	{
		delete[] arr;
		//delete * arr;
	}

	T *data()                          // returns a pointer to the underlying array
	{
		return arr;
	}

	void reserve(size_t newCapacity)   // resizes the vector to at least this many elements
	{
		T *temp = new T[newCapacity]();
		for (size_t i = 0; i < arrSize; i++)
		{
			if (i > newCapacity)
				break;
			temp[i] = arr[i];
		}
		delete[] arr;

		arrCapacity = newCapacity;
		arr = temp;

		delete temp;
	}

	void push_back(const T &value)     // adds an element to the end of the vector
	{
		if ((arrCapacity - 1) == arrSize)
		{
			reserve(arrSize * GROWTH_FACTOR);
		}

		arr[arrSize += 1] = value;
	}
	void pop_back()                    // drops the last element of the vector
	{
		T *temp = new T[arrCapacity -= 1]();
		for (size_t i = 0; i < arrCapacity; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;

		arrSize--;
		arr = temp;
	}

	T &at(size_t index)                // returns the element at the given element
	{
		return arr[index];
	}

	size_t size() const                // returns current number of elements
	{
		return arrSize;
	}
	size_t capacity() const            // returns maximum number of elements we can store
	{
		return arrCapacity;
	}


	TVECTOR(const TVECTOR &vec)
	{
		arr = new T[vec.arrCapacity]();
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;

		for (size_t i = 0; i < arrCapacity; i++)
		{
			arr[i] = vec.arr[i];
		}
	}

	TVECTOR& operator=(const TVECTOR &vec)
	{
		arr = new T[vec.arrCapacity]();
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;

		for (size_t i = 0; i < arrCapacity; i++)
		{
			arr[i] = vec[i];
		}
	}

	T& operator[] (size_t index)
	{
		arr = new T[index]();
		arrSize = index;
		arrCapacity = 0;
	}
};



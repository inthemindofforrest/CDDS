// tObjectPool.h
#pragma once

template<typename T>
class tObjectPool
{
	ObjectPool();                       // default initializes the object pool
	ObjectPool(size_t initialCapacity); // initializes the pool to have a set number of objects
	~ObjectPool();                      // destroys all objects

	T* free;                            // pointers to objects that can be reused
	T* used;                            // pointers to objects that are currently in use
	size_t freeCount;                   // number of objects that are free to use
	size_t usedCount;                   // number of objects that are in use

	T* retrieve();                      // returns a pointer to an object that will be used (returns null if none available)
	void recycle(T* obj);               // accepts a pointer that can be used in the future

	size_t capacity();                  // returns the total number of objects that this pool can provide
};

template<typename T>
tObjectPool<T>::ObjectPool()
{
}

template<typename T>
tObjectPool<T>::ObjectPool(size_t initialCapacity)
{
	capacity = initialCapacity;
	freeCount = initialCapacity;
	usedCount = 0;

	used = new T[initialCapacity];
	free = used[0];
}

template<typename T>
tObjectPool<T>::~ObjectPool()
{
}

template<typename T>
T * tObjectPool<T>::retrieve()
{
	free++;
	if (free != nullptr)
		return free;
	else
		return nullptr;
}

template<typename T>
void tObjectPool<T>::recycle(T * obj)
{
	for(int i = 0;i < usedCount; i++)
		if (used[i] == obj)
		{
			T * Temp = free;
			(free--) = used[i];
			used[i] = Temp;
		}
}

template<typename T>
size_t tObjectPool<T>::capacity()
{
	return capacity;
}

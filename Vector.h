#ifndef _VECTOR_H_
#define _VECTOR_H_H
#include "IndexOutofBounds.h"

template <class T>
class Vector {
public:
	Vector();		// create an empty vector
	Vector(int size);	// create a vector of size elements
	Vector(const Vector& r);	// copy ctor
	~Vector();
	T& operator[](int index) throw(IndexOutofBounds);
	// return the specified element, throws exception when index <0 or >=m_nSize
	int size();		// return the size of the vector
	int inflate(int addSize);	// expand the storage to m_nSize+addSize, return the new size

private:
	T *m_pElements;
	int m_nSize;
};

template <class T>
Vector<T>::Vector()// create an empty vector
{
	m_nSize = 0;
	m_pElements = NULL;
}

template <class T>
Vector<T>::Vector(int size)	// create a vector of size elements
{
	m_nSize = size;
	m_pElements = new T[m_nSize];
}

template <class T>
Vector<T>::Vector(const Vector& r)	// copy ctor
{
	this->m_nSize = r.m_nSize;
	m_pElements = new T[m_nSize];
	//ÄÚ´æ¿½±´º¯ÊýÔ­ÐÍ£º
	//void*memcpy(void*dest, const void*src,unsigned int count); 
	memcpy(this->m_pElements, r.m_pElements, sizeof(T) * m_nSize);
}

template <class T>
Vector<T>::~Vector()
{
	delete[] m_pElements;
	m_nSize = 0;
}

template <class T>
T& Vector<T>::operator[](int index) throw(IndexOutofBounds)
{
	if (index >= m_nSize || index < 0)
		throw IndexOutofBounds();
	return m_pElements[index];
}
// return the specified element, throws exception when index <0 or >=m_nSize

template <class T>
int Vector<T>::size()		// return the size of the vector
{
	return this->m_nSize;
}

template <class T>
int Vector<T>::inflate(int addSize)	// expand the storage to m_nSize+addSize, return the new size
{
	T *t = this->m_pElements;					//Ê×ÏÈ±£´æm_nElementsÀïÃæµÄÄÚÈÝ
	m_pElements = new T[addSize + m_nSize];		//À©³ä´óÐ¡
	memcpy(m_pElements, t, m_nSize * sizeof(T));	//¿½±´ÄÚ´æ
	m_nSize += addSize;							//Ôö´ó³ß´ç±ê¼Ç
	delete[] t;									//É¾³ýÁÙÊ±±äÁ¿t
	return m_nSize;								//·µ»ØÀ©³äºóµÄÊýÁ¿
}
#endif

#ifndef ASSIGNMENT_3_AN_VECTOR_H
#define ASSIGNMENT_3_AN_VECTOR_H
/**
 * @file AN_Vector.h
 * @authors Author 1 : Ahmed Yehia Abdel-moaty(20210049)
 *         Author 2 : Nada Mohammed Abdel-Hafez(20210422)
 * @brief This file contains the declaration of the AN_Vector class
 * @version 1.0
 * @date 2022-012-7
 * @note This file is part of the 3rd assignment of the OOP course
 */


#include <bits/stdc++.h>
using namespace std;

template <class T> class AN_Vector;

template <class T>
ostream& operator<<(ostream& os, const AN_Vector<T>& v);
/**
 * @brief This class represents a vector
 * @tparam T The type of the elements in the vector
 * @note This class is a template class
 * @note This class is a container class
 */
template <class T>
class AN_Vector {
private:
    /**
     * @brief The array that holds the elements of the vector
     */
    T *data;
    /**
     * @brief The size of the vector
     */
    int size;
    /**
     * @brief The capacity of the vector
     */
    int capacity;
    typedef T* iterator;
public:
    // Constructors and Big 4
    /**
     * @brief Construct a new AN_Vector object
     * @note This is the default constructor
     */
    AN_Vector (int cap);
    /**
     * @brief Construct a new AN_Vector object
     * @param ptr
     * @param n
     */
    AN_Vector (T *ptr, int n);
    /**
     * @brief Construct a new AN_Vector object
     * @param rhs
     */
    AN_Vector (const AN_Vector &rhs);
    /**
     * @brief Destroy the AN_Vector object
     */
    ~AN_Vector();
    /**
     * @brief Copy assignment operator
     * @param rhs
     * @return AN_Vector<T>&
     */
    AN_Vector &operator=(const AN_Vector<T> &rhs);
    /**
     * @brief Move assignment operator
     * @param rhs
     * @return AN_Vector<T>&
     */
    AN_Vector &operator=(AN_Vector &&rhs);
    // Access operations
    /**
     * @brief  get the element at a specific index
     * @param index
     * @return T&
     */
    T& operator[](int index);
    // Modifying operations
    /**
     * @brief  push an element to the end of the vector
     * @return size of the  vector
     */
    int push_back(T element);
    /**
     * @brief  pop an element from the end of the vector
     * @return the last element of the vector
     */
    T pop_back();
   /**
    * @brief  erase an element from the vector
    * @param i
    */
   void erase(iterator i );
    /**
     * @brief  erase a range of elements from the vector
     * @param i1
     * @param i2
     */
   void erase(iterator i1, iterator i2);
   /**
    * @brief  clear the vector
     */

  void clear();
    /**
     * @brief  insert an element at a specific index
     * @param index
     * @param element
     * @return size of the vector
     */
   void insert(iterator i , T element);
    // iterators
    /**
     * @brief  get the first element of the vector
     * @return iterator
     */
    iterator begin();
    /**
     * @brief  get the last element of the vector
     * @return iterator
     */
    iterator end();
    // Comparison operations
    /**
     * @brief  check if two vectors are equal
     * @return true if they are equal
     * @return false if they are not equal

     * @param  rhs
     */
    bool operator==(const AN_Vector<T>& rhs);
    /**
     * @brief  check if a vector is smaller than another vector
     * @return true if it is smaller
     * @return false if it is not smaller
     * @param  rhs
     */
    bool operator< (const AN_Vector<T>& rhs);
    // Capacity operations
    /**
     * @brief  get the size of the vector
     * @return int
     */
    int Size() const;
    /**
     * @brief  get the capacity of the vector
     * @return int
     */
    int Capacity() const;
    /**
     * @brief  resize the vector
     * @return int
     */
    int resize();
    /**
    * @brief  check if the vector is empty
    * @return true if the vector is empty
    * @return false if the vector is not empty
    */
    bool empty();
    // Friends
    /**
     * @brief  print the vector
     * @param os
     * @param v
     * @return ostream&
     */
    friend ostream& operator << <T> (ostream& out, const AN_Vector<T> &v);
};

#endif //ASSIGNMENT_3_AN_VECTOR_H

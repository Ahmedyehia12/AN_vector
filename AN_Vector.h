#ifndef ASSIGNMENT_3_AN_VECTOR_H
#define ASSIGNMENT_3_AN_VECTOR_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include<vector>
using namespace std;
template <class T>
class AN_Vector {
protected:
        T *data;
        int size ;
        int capacity;
public:
    // Constructors and Big 4
    AN_Vector (int cap=2){
        capacity = cap;
        size = 0;
        data = new T[capacity];
    };

    AN_Vector (T*, int  n );
    AN_Vector (const AN_Vector&);
    ~AN_Vector();
    AN_Vector &operator=(const AN_Vector<T> & other);
    AN_Vector &operator=(const AN_Vector&& other);
    // Access operations
    T& operator[](int);
    // Modifying operations
    int push_back(T element);
    T pop_back();
    //void erase(AN_Vector<T>: );
    //void erase(iterator1, iterator2);
    void clear();
   //void insert(iterator, T);
    // Iterators
//    iterator begin();
//    iterator end();
    // Comparison operations
    bool operator==(const AN_Vector<T>& other);
    bool operator< (const AN_Vector<T>& other);
    // Capacity operations
    int Size() const;
    int Capacity() const;
    int resize();
    bool empty();
    // Friends
    //friend ostream& operator <<  (ostream& out, AN_Vector<T>v) ;
};


#endif //ASSIGNMENT_3_AN_VECTOR_H

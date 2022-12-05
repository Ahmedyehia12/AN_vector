#ifndef ASSIGNMENT_3_AN_VECTOR_H
#define ASSIGNMENT_3_AN_VECTOR_H

#include <iostream>
using namespace std;
template <class T>
class AN_Vector {
    private:
        T *data;
        int size;
        int capacity;
public:
    // Constructors and Big 4
    AN_Vector (int);
    AN_Vector (T*, int  n );
    AN_Vector (const AN_Vector&);
    ~AN_Vector();
    AN_Vector &operator=(const AN_Vector<T>&);
//    AN_Vector &operator=(const Vector&&);
    // Access operations
    T& operator[](int);
    // Modifying operations
//    int push_back(T);
//    T pop_back();
//    void erase(iterator);
//    void erase(iterator1, iterator2);
//    void clear();
//    void insert(iterator, T);
    // Iterators
//    iterator begin();
//    iterator end();
    // Comparison operations
    bool operator==(const AN_Vector<T>&);
    bool operator< (const AN_Vector<T>&);
    // Capacity operations
    int Size() const;
    int Capacity() const;
    int resize();
    bool empty();
    // Friends
    friend ostream& operator << (ostream& out, AN_Vector<T>);
};

#endif //ASSIGNMENT_3_AN_VECTOR_H

#ifndef ASSIGNMENT_3_AN_VECTOR_H
#define ASSIGNMENT_3_AN_VECTOR_H

#include <bits/stdc++.h>
using namespace std;
template <class T>
class AN_Vector {
private:
    T *data;
    int size;
    int capacity;
    typedef T *iterator;

public:

    // Constructors and Big 4
    AN_Vector(int cap);


    AN_Vector(T *ptr, int n);

    AN_Vector(const AN_Vector &rhs);

    ~AN_Vector();

    AN_Vector &operator=(const AN_Vector<T> &rhs);

    AN_Vector &operator=(AN_Vector &&rhs);

    // Access operations
    T &operator[](int index);

    // Modifying operations
    int push_back(T element);

    T pop_back();

//   void erase(AN_Vector<T>: );
    void erase(iterator i1, iterator i2);

    void clear();

//    void insert(iterator, T);
// iterator
    iterator begin();

    iterator end();


    // Comparison operations
    bool operator==(const AN_Vector<T> &rhs);

    bool operator<(const AN_Vector<T> &rhs);

    // Capacity operations
    int Size() const;

    int Capacity() const;

    int resize();

    bool empty();
    // Friends
    //friend ostream& operator << (ostream& out, const AN_Vector<T> &v);
};
#endif //ASSIGNMENT_3_AN_VECTOR_H

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
    AN_Vector(){
        cout<< "Default constructor called" << endl;
    }

};

#endif //ASSIGNMENT_3_AN_VECTOR_H

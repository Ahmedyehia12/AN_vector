#include"AN_Vector.h"

template<class T>

        int AN_Vector<T>::resize() {
         if (size >= capacity) {
          capacity *= 2;
          T *temp = new T[capacity];
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        delete []temp;
    }
    return capacity;
}

template<class T>
int AN_Vector<T>::Size() const {
    return size;
}

template<class T>
bool AN_Vector<T>::empty() {
    return size == 0;
}

template<class T>
int AN_Vector<T>::Capacity() const {
    return capacity;
}

template<class T>
int AN_Vector<T>::push_back(T element) {
    if(size>=capacity){
        resize();
        data[size++] = element;
    }
    else{
        data[size++] = element;
    }
    return size;
}

template<class T>
T AN_Vector<T>::pop_back() {
    if (size == 0) {
        cout << "Error: Vector is empty" << endl;
        exit(-1);
    }
    return data[--size];
}

template<class T>
void AN_Vector<T>::clear() {
 size = 0;
}

template<class T>
bool AN_Vector<T>::operator==(const AN_Vector<T> & other) {
    if(size != other.size)
        return false;
    int cnt = 0;
    for(int i=0;i<size;i++){
        if(this->data[i] == other.data[i]){
            cnt++;
        }
    }
    if(cnt == size)
        return true;
    else
        return false;
}



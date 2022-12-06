#include"AN_Vector.h"

// Constructors and Big 4
template<class T>
AN_Vector<T> :: AN_Vector (int cap)
    :size{0}, capacity{cap}, data{new T[capacity]} {}

template<class T>
AN_Vector<T> :: AN_Vector (T *ptr, int n)
    :size{n}, capacity{n}, data{new T[capacity]}{
    for (int i = 0;i<n;i++){
        data[i] = ptr[i];
    }
}
template<class T>
AN_Vector<T> :: AN_Vector (const AN_Vector &rhs)
    :size{rhs.size}, capacity{rhs.capacity}, data{new T[capacity]}{
    for (int i = 0;i<rhs.Size();i++){
        data[i] = rhs.data[i];
    }
}
template<class T>
AN_Vector<T> :: ~AN_Vector(){
    delete[] data;
}
template<class T>
AN_Vector<T> &AN_Vector <T> :: operator=(const AN_Vector<T> &rhs){
    if(this != &rhs){
        delete[] data;
        data = new T[rhs.capacity];
        size = rhs.size;
        for(int i = 0;i<size;i++){
            data[i] = rhs.data[i];
        }
    }
    return *this;
}
template<class T>
AN_Vector<T> &AN_Vector <T> :: operator=(AN_Vector &&rhs){
    if(this != &rhs){
        delete[] data;
        data = rhs.data;
        size = rhs.size;
        capacity = rhs.capacity;
        rhs.data = nullptr;
    }
    return *this;
}

// Access operations
template<class T>
T& AN_Vector<T> :: operator[](int index){
    if(index < 0 || index >= size){
        cout << "Error: Array index is out of range!" << endl;
        exit(-1);
    }
    return data[index];
}

// Modifying operations
template<class T>
int AN_Vector<T>::push_back(T element) {
    if(size<capacity){
       data[size++] = element;
    }
    else{
        resize();
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
//void insert(iterator, T);

// Iterators
//template<class T>
//iterator begin();
//template<class T>
//iterator end();

// Comparison operations
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
template<class T>
bool AN_Vector<T> :: operator< (const AN_Vector<T>& other){
if(size != other.size){
    return false;
}
else{
    for(int i=0;i<size;i++){
        if(data[i]<other.data[i])
            return false;
    }
    return true;
}
}

// Capacity operations
template<class T>
int AN_Vector<T>::Size() const {
    return size;
}
template<class T>
int AN_Vector<T>::Capacity() const {
    return capacity;
}
template<class T>
int AN_Vector<T>::resize() {
        T *temp = new T[capacity*2];
           capacity *= 2;
        for (int i = 0; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        //delete[]temp;
    return capacity;
}
template<class T>
bool AN_Vector<T>::empty() {
    return size == 0;
}

template<class T>
void AN_Vector<T>::erase(iterator i1, iterator i2) {
    if(i1 == i2){
        cout << "Error: No elements to erase" << endl;
        exit(-1);
    }
    int cnt = 0;
    for(iterator i = i1;i!=i2;i++){
        cnt++;
    }
    for(iterator i = i1;i!=i2;i++){
        *i = *(i+cnt);
    }
    size -= cnt;
}

template<class T>
T* AN_Vector<T>::begin() {
    return data;
}
template<class T>
T* AN_Vector<T>::end() {
    return data+size;
}

template<class T>
void AN_Vector<T>::erase(AN_Vector::iterator i) {
    if(i > end() || i<begin()){
        cout << "Error: No elements to erase" << endl;
        exit(-1);
    }
    for(iterator j = i;j!= end();j++){
        *j = *(j+1);
    }
    size--;

}

template<class T>
void AN_Vector<T>::insert(AN_Vector::iterator i , T element) {
    if(i>end() || i<begin()){
        cout << "Error: Invalid iterator" << endl;
        exit(-1);
    }
    else{
        if(size != capacity){
           for(iterator j = end();j!=i;j--){
               *j = *(j-1);
            }
            *i = element;
            size++;
        }
        else{
            resize();
            for(iterator j = end();j!=i;j--){
                *j = *(j-1);
            }
            *i = element;
            size++;

        }
    }
}









// ostream operator overloading
//template<class T>
//ostream& operator << (ostream& out, const AN_Vector<T> &v) {
//
//}
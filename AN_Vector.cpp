#include"AN_Vector.h"

// Constructors and Big 4
template<class T>
AN_Vector<T> :: AN_Vector (int cap)
    :size{0}, capacity{cap}, data{new T[capacity]}{  // constructor to initialize by specific capacity and size to zero
}
template<class T>
AN_Vector<T> :: AN_Vector (T *ptr, int n)
    :size{n}, capacity{n}, data{new T[capacity]}{   // constructor to initialize by n elements from an array
    for (int i = 0;i<n;i++){
        data[i] = ptr[i];
    }
}
template<class T>
AN_Vector<T> :: AN_Vector (const AN_Vector &rhs)
    :size{rhs.size}, capacity{rhs.capacity}, data{new T[capacity]}{
    // create a copy of the pointed data
    for (int i = 0;i<rhs.Size();i++){
        data[i] = rhs.data[i];
    }
}
template<class T>
AN_Vector<T> :: ~AN_Vector(){
    // delete allocated memory
    delete[] data;
}
template<class T>
AN_Vector<T> &AN_Vector <T> :: operator=(const AN_Vector<T> &rhs){
    // check if we are self assigning
    if(this != &rhs){
        // delete current storage
        delete[] data;
        // allocate new storage on the heap
        capacity = rhs.capacity;
        data = new T[capacity];
        size = rhs.size;
        // perform the copy
        for(int i = 0;i<size;i++){
            data[i] = rhs.data[i];
        }
    }
    return *this;
}
template<class T>
AN_Vector<T> &AN_Vector <T> :: operator= ( AN_Vector<T> &&rhs)  {
    // check if we are self assigning
     if(this != &rhs){
        // delete current storage
        delete[] data;
        // copy the pointer to lhs from rhs
        data = rhs.data;
        size = rhs.size;
        capacity = rhs.capacity;
        // null out the rhs pointer
        rhs.data = nullptr;
        rhs.size = 0;
        rhs.capacity =0;
    }
    return *this;
}


// Access operations
template<class T>
T& AN_Vector<T> :: operator[](int index){
    // check if the index is in the range of the vector or not
    if(index < 0 || index >= size){
        throw out_of_range("Index element is out of range");
    }
    return data[index];
}

// Modifying operations
template<class T>
int AN_Vector<T>::push_back(T element) {
    // check if the vector is full
    if(size<capacity){
        // if not full, add the element to the end
       data[size++] = element;
    }
    else{
        // if full, resize the vector
        resize();
        data[size++] = element;
    }
    // return the size of the vector
    return size;
}
template<class T>
T AN_Vector<T>::pop_back() {
    //checking if the vector is empty
    if (size == 0) {
        cout << "Error: Vector is empty" << endl;
        exit(-1);
    }
    //decrementing the size of the vector
    return data[--size];
}
template<class T>
void AN_Vector<T>::erase(iterator i1, iterator i2) {
    //checking if the iterators are valid
    if(i1 == i2){
        cout << "Error: No elements to erase" << endl;
        exit(-1);
    }
    int cnt = 0;
    for(iterator i = i1;i!=i2;i++){
        //counting the number of elements to be erased
        cnt++;
    }
    for(iterator i = i1;i!=i2;i++){
        //shifting the elements to the left
        *i = *(i+cnt);
    }
    //decrementing the size of the vector
    size -= cnt;
}
template<class T>
void AN_Vector<T>::erase(AN_Vector<T>::iterator i) {
    //checking if the iterator is valid
    if(i > end() || i<begin()){
        cout << "Error: No elements to erase" << endl;
        exit(-1);
    }
    for(iterator j = i;j!= end();j++){
        //shifting the elements to the left
        *j = *(j+1);
    }
    //decrementing the size of the vector
    size--;

}
template<class T>
void AN_Vector<T>::clear() {
    //setting the size to 0
    size = 0;
}
template<class T>
void AN_Vector<T>::insert(AN_Vector<T>::iterator i , T element) {
    //checking if the iterator is valid
    if(i>end() || i<begin()){
        cout << "Error: Invalid iterator" << endl;
        exit(-1);
    }
    else{
        if(size != capacity){
            if(i == end()){
                //if the iterator is at the end of the vector, just add the element
                data[size++] = element;
            }
            else{
                //if the iterator is not at the end of the vector, shift the elements to the right
                //storing the element at the iterator
                for(iterator j = end();j!=i;j--){
                    //shifting the elements to the right
                    *j = *(j-1);
                }
                //adding the element at the iterator
                *i = element;
                size++;
            }
        }
        else{
            //resizing the vector
            resize();
           if(i == end()){
                //if the iterator is at the end of the vector, just add the element
                data[size++] = element;
              }
              else{
                //if the iterator is not at the end of the vector, shift the elements to the right
                for(iterator j = end();j!=i;j--){
                     //shifting the elements to the right
                     *j = *(j-1);
                }
                //adding the element at the iterator
                *i = element;
                size++;
           }

        }
    }
}

// Iterators
template<class T>
T* AN_Vector<T>::begin(){
    //  returns an iterator which points to the first element of the vector
    return data;
}
template<class T>
T* AN_Vector<T> :: end(){
    //  returns an iterator which points to past the end element of the vector
    return data + size;
}

// Comparison operations
template<class T>
bool AN_Vector<T>::operator==(const AN_Vector<T> & other) {
    //checking if the sizes are equal
    if(size != other.size)
        return false;
    //checking if the elements are equal
    int cnt = 0;
    for(int i=0;i<size;i++){
        if(this->data[i] == other.data[i]){
            cnt++;
        }
    }
    //if the elements are equal then return true
    if(cnt == size)
        return true;
    else
        //if the elements are not equal then return false
        return false;
}
template<class T>
bool AN_Vector<T> :: operator< (const AN_Vector<T>& other)
{
    //checking if the sizes are equal
    if (size != other.size) {
        return false;}
        //checking if the elements are equal
    else {
        for (int i = 0; i < size; i++) {
            if (data[i] < other.data[i])
                // if the elements are not equal then return false
                return false;
        }
        //if the elements are equal then return true
        return true;
    }
}

// Capacity operations
template<class T>
int AN_Vector<T>::Size() const {
    //returning the size of the vector
    return size;
}
template<class T>
int AN_Vector<T>::Capacity() const {
    //returning the capacity of the vector
    return capacity;
}
template<class T>
int AN_Vector<T>::resize() {
    //creating a new array with double the capacity
    T *temp = new T[capacity*2];
    capacity *= 2;
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    //deleting the old array
    delete[] data;
    //pointing the data to the new array
    data = temp;
    //delete[]temp;
    //returning the new capacity
    return capacity;
}
template<class T>
bool AN_Vector<T>::empty() {
    //checking if the size is 0
    return size == 0;
}

// ostream operator overloading
template<class T>
ostream& operator << (ostream& out, const AN_Vector<T> &v) {
    for(int i=0;i<v.size;i++){
        //printing the elements of the vector
        out << v.data[i] << " ";
    }
    return out;
}
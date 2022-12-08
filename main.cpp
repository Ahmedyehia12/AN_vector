/**
 * @brief The main function
 */


#include "AN_Vector.cpp"


int main() {

/**
 * @brief test the AN_Vector class
 */
int arr[5] = {1,2,3,4,5};
AN_Vector<int> s1 (arr,5);
s1.erase(s1.begin()+3,s1.end());
cout<<s1<<endl;
cout<<*(s1.end()-1)<<endl;
    return 0;
}

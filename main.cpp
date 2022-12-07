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
    AN_Vector<int> s2(2);
    s2 = std::move(s1);
cout<<s1.Size()<<endl;
cout<<s2<<endl;
/*s.push_back(2);
s.push_back(3);
s.push_back(4);
s.push_back(5);
s.push_back(6);
s.push_back(7);
s.push_back(8);
cout<<s<<endl;
s.insert(s.begin()+2, 9);
cout<<s;*/
    return 0;
}

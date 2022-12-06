#include "AN_Vector.cpp"

int main() {
//    AN_Vector<int> s(2);
//    s.push_back(3);
//    s.push_back(3);
//    AN_Vector<int> s2(2);
//    s2.push_back(3);
//    s2.push_back(3);
//    cout << (s == s2) << endl;
//    s.push_back(4);
//    cout << s.Capacity() << endl;
//    s.pop_back();
//    cout << s.Size();

    int arr [3] = {1,2 ,3};
    int *p = arr;
    int arr2 [4] = {1,6 ,3, 4};
    int *p2 = arr2;
    AN_Vector <int> v{p, 3};
    AN_Vector <int> v2{p2, 4};
    v = move(v2);
//    cout << v[5];


    return 0;
}

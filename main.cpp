#include "AN_Vector.cpp"

int main() {
    AN_Vector<int> s(2);
    s.push_back(3);
    s.push_back(3);
    AN_Vector<int> s2(2);

    s2.push_back(3);
    s2.push_back(3);
    cout << (s == s2) << endl;
    s.push_back(4);
    cout << s.Capacity() << endl;
    s.pop_back();
    cout << s.Size();
}

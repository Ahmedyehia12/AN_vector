#include "AN_Vector.cpp"

int main() {


AN_Vector<int> s (2);
s.push_back(2);
s.push_back(3);
s.push_back(4);
s.push_back(5);
s.push_back(22);
s.push_back(33);
s.push_back(44);
s.push_back(55);
s.push_back(222);
s.erase(s.end());
cout<<s<<endl;
    return 0;
}

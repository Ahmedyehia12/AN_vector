#include "AN_Vector.cpp"

int main() {


AN_Vector<int> s (2);
s.push_back(2);
s.push_back(3);
s.push_back(4);
s.push_back(5);
s.push_back(6);
s.push_back(7);
s.push_back(8);
cout<<s<<endl;
s.insert(s.begin()+2, 9);
cout<<s;
    return 0;
}

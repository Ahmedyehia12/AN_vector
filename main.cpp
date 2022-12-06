#include "AN_Vector.cpp"

int main() {


AN_Vector<int> s (2);
s.push_back(2);
s.push_back(3);
s.push_back(5);
s.push_back(7);
s.erase(s.begin(),s.begin()+2);
s.push_back(80);
cout<<s<<endl;
    return 0;
}

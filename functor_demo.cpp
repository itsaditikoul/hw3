#include <iostream>
#include <string>
using namespace std;

//func 1 - by alpha
struct AlphaStrComp {
  bool operator() (const string& lhs, const string& rhs) const {
    return lhs<rhs;
  }
};

//func 2 - by len 
struct LengthStrComp {
  bool operator() (const string& lhs, const string& rhs) const {
    return lhs.size()<rhs.size();
  }
};

// temp func - accepts any comp functr
template <class Comparator>
void DoStringCompare(const string& s1, const string& s2, Comparator comp) {
  cout << comp(s1, s2) << "\n";   
}

int main() {
  string s1="Blue";
  string s2= "Red";
  AlphaStrComp comp1;
  LengthStrComp comp2;

  //1→"Blue"<"Red" alpha wise
  DoStringCompare(s1, s2, comp1);

  //0→length("Blue")=4 isnt< length("Red")=3
  DoStringCompare(s1, s2, comp2);

  return 0;
}

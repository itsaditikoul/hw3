#include "heap.h"
#include <iostream>
#include <string>
#include <vector>
#include <functional> // std::greater
using namespace std;

int main(){
  {
  Heap<int> h;
  vector<int> in = {5,0,10,-3,7};
  for (int x:in) h.push(x);
  cout<<"min-heap ints: ";
  while (!h.empty()) {
    cout<< h.top() <<" "; //expect sorted ascending: -3 0 5 7 10
    h.pop();
  }
  cout<<"\n";
  }




  {
  Heap<int, std::greater<int>> h(2,std::greater<int>()); 
  vector<int> in = {5,0,10,-3,7};
  for(int x:in) h.push(x);
  cout << "max-heap ints: ";
  while (!h.empty()) {
    cout<< h.top()<< " "; //expect descending 10 7 5 0 -3
    h.pop();
  }
  cout<<"\n";
  }




  struct ShorterFirst {
    bool operator()(const string& a, const string& b) const {
      return a.size()<b.size();
    }
  };

  {
    Heap<string, ShorterFirst> h(2, ShorterFirst{});
    vector<string> in={"pear","fig","pineapple","kiwi","plum"};
    for(auto& s:in) h.push(s);
    cout<< "Shorter-first strings: ";
    while (!h.empty()) {
      cout<<h.top()<<" "; //shortest to longest
      h.pop();
    }
    cout<<"\n";
  }



  {
    Heap<int> h(3); //m=3, less<int>
    vector<int> in = {9,1,8,2,7,3,6,4,5};
    for(int x:in) h.push(x);
    cout<<"Ternary min-heap ints: ";
    while (!h.empty()) {
      cout<<h.top()<<" "; // expect ascending 1..9
      h.pop();
    }
    cout<<"\n";
  }


  {
    Heap<int> h;
    try { h.top(); }
    catch (const std::underflow_error& e) { cout << "top() threw as expected\n"; }
    try { h.pop(); }
    catch (const std::underflow_error& e) { cout << "pop() threw as expected\n"; }
  }

  return 0;

}
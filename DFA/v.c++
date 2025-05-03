#include <vector>
#include <iostream>
using namespace std;

int main() {
  vector<int> v(10, 1);
  for(int i : v) {
    cout << i << endl;
  }
  int v2[10]; 
  for(int i=0; i<10; i++) {
    v2[i] = 2;
  }
  for(int i : v2) {
    cout << i << endl;
  }
  return 0;
}
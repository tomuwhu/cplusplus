#include <iostream>
#include <vector>
#include <format>
using namespace std;
unsigned short c = (unsigned short)'A';
vector<int> v = {1, 2, 3};
int main() {
  v.push_back(5);
  for(int i : v) {
    cout << "Hello World! " << i << endl;
  }
  while (c <= (unsigned short)'Z') {
    cout << format("' {} ' karakter kódja {}", (char)c, c ) << endl;
    c++;
  }
  return 0;
}
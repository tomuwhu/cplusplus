#include <iostream>
using namespace std;
int main() {
  long n, o = 0;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    o += x;
  }
  cout << n * (n+1) / 2 - o << endl;
}
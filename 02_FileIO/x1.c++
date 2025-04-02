#include <iostream>
using namespace std;

vector<string> v = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
int main() {
    int a, b, i;
    cin >> a >> b;
    for (i = a; i <= b; i++) {
      if (i < 10) cout << v.at(i - 1) << endl;
      else if (i % 2) cout << "odd" << endl;
      else cout << "even" << endl;
    }
    return 0;
}
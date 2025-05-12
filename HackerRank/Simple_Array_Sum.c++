#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
// https://www.hackerrank.com/challenges/simple-array-sum/problem
int main()
{ 
  vector<int> ar = {32, 12, 32, 12, 432};
  auto osszeg = 0;
  for (auto i : ar) osszeg += i;
  cout << osszeg << endl;
  return 0;
}

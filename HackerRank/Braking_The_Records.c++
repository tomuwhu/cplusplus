#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{ 
  vector<int> scores = {10, 5, 20, 20, 4, 5, 2, 25, 1};
  int ret[2] = {0, 0};
  int i = 0;
  int min = scores[0];
  int max = scores[0];
  int mincount = 0;
  int maxcount = 0;
  for (i = 1; i< scores.size(); i++) {
    if (scores[i] < min) {
      min = scores[i];
      mincount++;
    }
    if (scores[i] > max) {
      max = scores[i];
      maxcount++;
    }
  }
  ret[0] = maxcount;
  ret[1] = mincount;
  for (i = 0; i < 2; i++) {
    cout << ret[i] << endl;
  }
  return 0;
}
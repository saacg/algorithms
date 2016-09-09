#include <iostream>
#include <vector>
#include <cmath>
#include "Problem3.h"

using namespace std;


int main(){
  int nums[] = {1, 100, 329, 2, 331};
  int len = 5;

  cout << Sum(&nums[0], len) << endl;

  return 0;
}

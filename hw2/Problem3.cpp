// Isaac Goldman U14381760 //
// EC330                   //
// HW 2 Proble3.cpp        //
/////////////////////////////

#include <iostream>
#include <vector>
#include <cmath>
#include "Problem3.h"

using namespace std;

int Sum(int* nums, int len){

                
  int sum = 0;  
  int temp, vecLen, diff;	
  vector<int> sumVector;

  // checks if any numbers in the passed in array equal 330, if so, the program terminates here and returns 330
  for(int i = 0; i < len; i++){
    if(nums[i] == 330){
      return 330;
    }
    // iterates through the passed-in array and stores all the sums of two unique elements in sumVector  
    for(int j = i + 1; j < len; j++){
      temp = nums[i] + nums[j]; 
      sumVector.push_back(temp);
    }
  }

  vecLen = sumVector.size();
 
  // iterates through the sums of the pairs of array elements and sums them with a third element for all unique combinations and stores them in sumVector
  for(int i = 0; i < vecLen; i++){
    for(int j = i + 2; j < len; j++){
      temp = sumVector[i] + nums[j];
      sumVector.push_back(temp);
    }
  }

 
  sum = *(sumVector.begin());
  diff = abs(330.0 - sum);

// iterates through the passed - in array and stores the absolute value of the difference between each element and 330, if the difference is 
// smaller than the previous difference, the element is stored in the sum variable as a possible return value
  for(int i = 0; i < len; i++){
    temp = abs(330.0 - nums[i]);
    if(temp < diff){
      diff = temp;
      sum = nums[i];
    }
  }

// repeats the same process as above for sumVector
  for(vector<int>::iterator it = sumVector.begin() + 1; it != sumVector.end(); ++it){
    temp = abs(330.0 - (*it));
    if (temp < diff){
      diff = temp;
      sum = (*it);
    }
  } 
  return sum;
}


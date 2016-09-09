#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;


void fourC(){

  string inputString; // stores all the characters in the input file
  string longestPal; // stores the longest palindrome 
  int strLength; // length of the input string
  int maxLength = 1; // stores the max length of the palindrome, starts at 1 as all single characters are palindromes
  int maxPos =0; // stores the starting index of the current longest palindrome
  int firstPos, lastPos; // indices of the start and end to the palindrome 

  ifstream inputFile("BigData.txt");
  //  ifstream inputFile("testPal.txt");
  getline(inputFile, inputString); // reads all characters in the file in as one string
  strLength = inputString.length();

  // iterate through the string and compare the lengths of all even and odd palindromes
  for(int i = 1; i < strLength; i++){

    int currLength; // stores current length of the string between firstPos and lastPos

    // find max length of even palindromes
    // firstPos and lastPos begin next to each other
    firstPos = i - 1;
    lastPos =  i;
    
    // while the characters at indices firstPos and lastPos are equal, decrement firstPos and increment lastPos to test the length of the palindrome
    while(firstPos >= 0 && lastPos < strLength && inputString[firstPos] == inputString[lastPos]){

      currLength = lastPos - firstPos + 1;

      // update maxLength and maxPos if the current palindrome is longer
      if(currLength > maxLength){
	maxLength = currLength;
	maxPos = firstPos;
      }

      firstPos--;
      lastPos++;
    }

    // find max length of odd palindromes
    // first Pos and lastPos begin one character apart from each other
    firstPos = i - 1;
    lastPos = i + 1;

    // while the characters at indices firstPos and lastPos are equal, decrement firstPos and increment lastPos to test the length of the palindrome
    while(firstPos >= 0 && lastPos < strLength && inputString[firstPos] == inputString[lastPos]){

      currLength = lastPos - firstPos + 1;

      // update maxLength and maxPos if the current palindrome is longer
      if(currLength > maxLength){
	maxLength = currLength;
	maxPos = firstPos;
      }

      firstPos--;
      lastPos++;
    }
  }

  // cout << maxPos << endl << maxLength;

  // concatenate longest palindrome into a string
  for(int i = maxPos; i < maxPos + maxLength; i++){
    longestPal += inputString[i];
  }

  cout << longestPal << endl; 

}

/*
int main(){

  fourC();


  return 0;
}
*/

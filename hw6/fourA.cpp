// Isaac Goldman
// U14381760
// EC330 HW6 problem 4a 
// 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// uses a FSM to find strings that match BU ID specifications and counts how many IDs have digits that sum to
// greater than 28
void fourA(){

  char inputChar; // stores the character read in from text file
  int state = 0; // stores the current state
  int digitCount = 0; // counts the digits that come after "U" in a string
  int idCount = 0; // counts the number of IDs that have a sum > 28
  int sum = 0; // stores the sum of the digits in a potential BU ID

  // open the text file
    ifstream dataFile("BigData.txt"); 
  //ifstream dataFile("SmallData.txt");

    // loop through the FSM until all characters have been read in from the file
    while (dataFile >> noskipws >> inputChar){

    // switch statement controls FSM of 3 states
    switch(state){
      // state 0 is the base state, machine returns here when there is a break in the pattern
    case 0:
      digitCount = 0;  // clear the counter and sum
      sum = 0; 

      // state changes to 1 when a "U" is read in
      if(inputChar == 'U'){
	state = 1;
	break;
      }
      // otherwise, stay in state 0;
      else{
	break;
      }

      // machine stays in state 1 until 8 digits have been read in after the 'U'
    case 1:
      // if the character read in from the file is a number, add it to the sum 
      // and increment the counter
      if(inputChar >= '0' && inputChar <= '9'){
	sum += inputChar - '0';
	digitCount++;
	// move to state 2 if 8 digits have been read in in a row
	if(digitCount >= 8){
	  state = 2;
	}
	break;
      }
      // if the input character is a 'U', clear the digit counter and sum, but remain in the same state
      else if(inputChar == 'U'){
	digitCount = 0;
	sum = 0;
	break;
      }
      // if the input character is not a number or a 'U', return to state 0
      else {
	state = 0;
	break;
      }

      // state 2 evaluates if the string accumulated in state 1 is a BU ID with a sum > 28
      // and adds it to the total count of valid BU IDs
    case 2:
      // if the next character is a nondigit, and the sum > 28,
      // the string is a BU ID that matches the pattern and the total count is incremented
      if((inputChar > '9' || inputChar < '0') && sum > 28){
	idCount++;
      }
      // if the next character is a 'U', clear the count and sum, and go to state 1
      if(inputChar == 'U'){
	digitCount = 0;
	sum = 0;
	state = 1;
	break;
      }
      // otherwise, return to state 0
      else{
	state = 0;
	break;
      }
    }
  }

  // return the total number of BU IDs with a sum > 28
  cout << idCount << endl;

  // close the file
  dataFile.close();
}

/*
int main(){



  fourA();



  return 0;
}
*/


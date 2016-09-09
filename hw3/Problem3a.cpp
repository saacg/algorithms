///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3a.cpp                      //
///////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include "Problem3a.h"


using namespace std;

int main(int argc, const char * argv[]) {

  /*
 Compute the following sums, and provide the code that produced the result:
 i. 46 + 2 + 15
 ii. “abra” + “cadabra”
 iii. “temp“ + “lates “ + “are “ + “us” +”eful”
  */

/***********************************************************************************/
  // part i.

  // instantiate newCell objects of type int
  newCell<int> num1(46);
  newCell<int> num2(2);
  newCell<int> num3(15);
  newCell<int> iAnswerCell(0);

  // use overloaded operators to compute sum and write to object
  iAnswerCell = num1 + num2 + num3;

  // print sum to console
  cout << iAnswerCell.read() << endl;

  /***********************************************************************************/

  // part ii

  // instantiate newCell objects of type string
  newCell<string> string1("abra");
  newCell<string> string2("cadabra");
  newCell<string> iiAnswerCell("");

  // use overloaded operators to compute sum and write to object
  iiAnswerCell = string1 + string2;

  // print sum to console
  cout << iiAnswerCell.read() << endl;


 /***********************************************************************************/

  // part iii

  // instantiate newCell objects of type string
  newCell<string> string3("temp");
  newCell<string> string4("lates");
  newCell<string> string5("are");
  newCell<string> string6("us");
  newCell<string> string7("eful");
  newCell<string> iiiAnswerCell("");

  // use overloaded operators to compute sum and write to object
  iiiAnswerCell = string3 + string4 + string5 + string6 + string7;

  // print sum to console
  cout << iiiAnswerCell.read() << endl;


  return 0;
}

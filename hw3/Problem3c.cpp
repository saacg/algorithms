///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3c.cpp                      //
///////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include "Problem3c.h"

using namespace std;

int main(int argc, const char * argv[]) {

  /*
Create the following lists, print their content, and compute their products; provide
the code that produced the result:
i. 4 * 11
ii. “abcd” * “ef” * “ghijklm”

  */

/***********************************************************************************/
  // part i.

  // instantiate newCell objects of type int
  newCell<int> num1(4);
  newCell<int> num2(11);
  
  // instantiate cellList object of type int
  cellList<int> numList1(num1);

  // push back newCell objects to the cellList
  numList1.write(num2);

  // print content of list (separated by spaces)
  numList1.print();
 
  // call product function and print product to console
  cout << numList1.product() << endl;

  /***********************************************************************************/

  // part ii

  // instantiate newCell objects of type string
  newCell<string> string1("abcd");
  newCell<string> string2("ef");
  newCell<string> string3("ghijklm");

  // instantiate cellList object of type string
  cellList<string> stringList1(string1);

  // push back newCell objects to the cellList
  stringList1.write(string2);
  stringList1.write(string3);

  // print content of list (separated by spaces)
  stringList1.print();

  // call product function and print product to console
  cout << stringList1.product() << endl;

  return 0;
}

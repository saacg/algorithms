///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3b.cpp                      //
///////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include "Problem3b.h"

using namespace std;

int main(int argc, const char * argv[]) {

  /*
Create the following lists, print their content, and compute their sums; provide the
code that produced the result:
i. 12 + 22
ii. “al” + “go” + “rith” + “ms”
  */

/***********************************************************************************/
  // part i.

  // instantiate newCell objects of type int
  newCell<int> num1(12);
  newCell<int> num2(22);
  
  // instantiate cellList object of type int
  cellList<int> numList1(num1);

  // push back newCell objects to the cellList
  numList1.write(num2);

  // print content of list (separated by spaces)
  numList1.print();
 
  // call sum function and print sum to console
  cout << numList1.sum() << endl;

  /***********************************************************************************/

  // part ii

  // instantiate newCell objects of type string
  newCell<string> string1("al");
  newCell<string> string2("go");
  newCell<string> string3("rith");
  newCell<string> string4("ms");

  // instantiate cellList object of type string
  cellList<string> stringList1(string1);

  // push back newCell objects to the cellList
  stringList1.write(string2);
  stringList1.write(string3);
  stringList1.write(string4);

  // print content of list (separated by spaces)
  stringList1.print();

  // call sum function and print sum to console
  cout << stringList1.sum() << endl;

  return 0;
}

///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3                      //
///////////////////////////////////////
#include <iostream>
#include <string>
#include <cstdlib>
#include "newCell.h"
#include "cellList.h"

using namespace std;

int main(int argc, const char * argv[]) {
  newCell<int> num0(0);
  newCell<int> num1(46);
  newCell<int> num2(2);
  newCell<int> num3(15);
  newCell<int> num4(12);
  newCell<int> num5(24);
  newCell<int> num6(4);
  newCell<int> num7(11);
  newCell<string> string1("abra");
  newCell<string> string2("cadabra");
  newCell<string> string3("temp");
  newCell<string> string4("lates ");
  newCell<string> string5("are ");
  newCell<string> string6("us");
  newCell<string> string7("eful");
  newCell<string> string8("al");
  newCell<string> string9("go");
  newCell<string> string10("rith");
  newCell<string> string11("ms");
  newCell<string> string12("hi");
  newCell<string> string13("there");
  newCell<string> string14("hello");
  newCell<string> string15("kids");
  newCell<string> string16("abcd");
  newCell<string> string17("efg");
  newCell<string> string18("hijklm");
  //newCell<string> string8;  
  num0 = num6 * num7;
  string1 = string16 * string17 * string18;
  cout << num0.read() << endl << string1.read() << endl;
  cellList<int> testInt(num6);
  cellList<string> testString(string16);
  testString.write(string17);
  testString.write(string18);
  testInt.write(num7);

  cout << testInt.product() << endl << testString.product() << endl;
  string3 = string3 + string4 + string5 + string6 + string7; 

  cout << num1.read() << endl << string1.read() << endl << string3.read() << endl;
  cout << num2.read() * num3.read() << endl << (string12.read()) * (string13.read()) << endl
       << string14.read() * string15.read() << endl;
  cellList<int> cell1(num4);
  cellList<string> cell2(string8);
  
  
  cell1.write(num5);
  
  cell2.write(string9);
  cell2.write(string10);
  cell2.write(string11);
  

  cell1.print();
  cell2.print();
 

  cout << cell1.sum() << endl;
  cout << cell2.sum() << endl;


  return 0;
}

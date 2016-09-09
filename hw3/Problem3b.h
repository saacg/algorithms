///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3                           //
///////////////////////////////////////


#ifndef PROBLEM3B_H
#define PROBLEM3B_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <list>

using namespace std;

/* A class for storing and manipulating integers and strings */
template <class T>
class newCell
{
 private:
  T storedValue;
  newCell();   
 public:
  newCell(T initialValue);                // constructor
  T read();                               // return the content of the cell
  void write(T value);                    // write value to cell
  newCell& swap (newCell& otherCell);       // swap the contents of this cell with another
  newCell& operator=(newCell& otherCell);   // copy constructor
  newCell& operator+(newCell& otherCell);   // return the sum of this and otherCell
  newCell& operator*(newCell& otherCell);   // return the product of this and otherCell
};


template<class T>
newCell<T>::newCell()
{
  storedValue = NULL;
}

template<class T>
newCell<T>::newCell(T initialValue)
{
  storedValue = initialValue;
}

template<class T>
T newCell<T>::read()
{
  return storedValue;
}

template<class T>
void newCell<T>::write(T value)
{
  storedValue = value;
}

template<class T>
newCell<T>& newCell<T>::swap(newCell<T>& otherCell)
{
  T tmp = this->read();
  write(otherCell.read());
  otherCell.write(tmp);
  return *this;
}

template<class T>
newCell<T>& newCell<T>::operator=(newCell<T>& otherCell)
{
  write(otherCell.read());
  return *this;
}

template<class T>
newCell<T>& newCell<T>::operator+(newCell<T>& otherCell)
{
  newCell<T> *result = new newCell(this->read() + otherCell.read());
  return *result;
}

// overload the * operator for strings in order to more easily templatize overloading the * operator for the newCell class
string& operator*(const string& lhStr, const string& rhStr){
  string strMax;  // will be assigned to the longer string argument
  string strMin;  // will be assigned to the shorter string argument
  int lhLen = lhStr.length(); 
  int rhLen = rhStr.length();  
  int i = 0;
  string* productStr = new string;


  // compare the lengths of the passed-in strings
  // assign strMax and strMin
  if(lhLen > rhLen){
    strMax = lhStr;
    strMin = rhStr;
  }

  else{
    strMax = rhStr;
    strMin = lhStr;
  }

  // for the length of the lhs input, interleave concatenation of the characters of the stings
  for(; i < lhLen; i++){
    (*productStr).append(1,lhStr[i]);
    if(i < rhLen){
      (*productStr).append(1,rhStr[i]); 
    }
  }

  // if there are still remaining characters that have not yet been concatenated to the product, add them
  if(i < strMax.length()){
    (*productStr).append(strMax, i, strMax.npos);
  }
  return *productStr;
}

// overload the * operator for newCell objects
// because the * operator for string is overloaded, this can be implemented in 
// the same way that the + operator was overloaded for newCell
template<class T>
newCell<T>& newCell<T>::operator*(newCell<T>& otherCell){
  newCell<T> *result = new newCell(this->read() * otherCell.read());
  return *result;
}

// a class for storing newCells to a list
template<class T> 
class cellList {

 private:
  cellList();
  list< newCell<T> > cList;

 public:
  cellList(newCell<T>& numcell);
  void write(newCell<T>& numcell);
  void print();
  T sum();
  T product();

};

// custom constructor - instantiate cellList with a newCell object
template<class T>
cellList<T>::cellList(newCell<T>& numcell){
  cList.push_back(numcell);
}

// add newCell object to the end of the cellList
template<class T>
void cellList<T>::write(newCell<T>& numcell){
  cList.push_back(numcell);
}

// print the newCell objects in the cellList - separated by spaces
template<class T>
void cellList<T>::print(){
  for(typename list< newCell<T> >::iterator it = cList.begin(); it != cList.end(); it++){
    cout << it->read() << " ";
  }
  cout << endl;
}

// add the elements in the cellList together, return the sum
template<class T>
T cellList<T>::sum(){
  newCell<T> cellSum(cList.begin()->read());
  for(typename list< newCell<T> >::iterator it = ++cList.begin(); it != cList.end(); it++){
    cellSum = cellSum + (*it);
  }
  return cellSum.read();
}

// multiply the elements in the cellList together, return the product
template<class T>
T cellList<T>::product(){
  newCell<T> cellProduct(cList.begin()->read());
  for(typename list< newCell<T> >::iterator it = ++cList.begin(); it != cList.end(); it++){
    cellProduct = cellProduct * (*it);
  }
  return cellProduct.read();
}


#endif 

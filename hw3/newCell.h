///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3                           //
///////////////////////////////////////


#ifndef NEWCELL_H
#define NEWCELL_H
#include <iostream>
#include <cstdlib>
#include <string>

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

  if(lhLen > rhLen){
    strMax = lhStr;
    strMin = rhStr;
  }

  else{
    strMax = rhStr;
    strMin = lhStr;
  }

  for(; i < lhLen; i++){
    (*productStr).append(1,lhStr[i]);
    if(i < rhLen){
      (*productStr).append(1,rhStr[i]); 
    }
  }

  if(i < strMax.length()){
    (*productStr).append(strMax, i, strMax.npos);
  }
  return *productStr;
}

template<class T>
newCell<T>& newCell<T>::operator*(newCell<T>& otherCell){
  newCell<T> *result = new newCell(this->read() * otherCell.read());
  return *result;
}

#endif /* newCell_hpp */

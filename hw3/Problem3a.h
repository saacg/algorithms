///////////////////////////////////////
//Isaac Goldman                      //
//U14381760                          //
//EC330 HW3                          //
//Problem3a.h                        //
///////////////////////////////////////


#ifndef PROBLEM3A_H
#define PROBLEM3A_H
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



#endif 

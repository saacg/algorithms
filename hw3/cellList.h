#ifndef CELLLIST_H
#define CELLLIST_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include "newCell.h"

using namespace std;



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

template<class T>
cellList<T>::cellList(newCell<T>& numcell){
  cList.push_back(numcell);
}

template<class T>
void cellList<T>::write(newCell<T>& numcell){
  cList.push_back(numcell);
}

template<class T>
void cellList<T>::print(){
  for(typename list< newCell<T> >::iterator it = cList.begin(); it != cList.end(); it++){
    cout << it->read() << " ";
  }
  cout << endl;
}

template<class T>
T cellList<T>::sum(){
  newCell<T> cellSum(cList.begin()->read());
  for(typename list< newCell<T> >::iterator it = ++cList.begin(); it != cList.end(); it++){
    cellSum = cellSum + (*it);
  }
  return cellSum.read();
}

template<class T>
T cellList<T>::product(){
  newCell<T> cellProduct(cList.begin()->read());
  for(typename list< newCell<T> >::iterator it = ++cList.begin(); it != cList.end(); it++){
    cellProduct = cellProduct * (*it);
  }
  return cellProduct.read();
}


#endif

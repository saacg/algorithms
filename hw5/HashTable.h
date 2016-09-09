// Isaac Goldman
// U14381760
// EC 330 HW 5
// Problem 5

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <cstdlib>
#include <string>
#include <set>


//using namespace std;

class HashTable {

 public:
  HashTable(const char* fileName);
  void SpellCheck(std::string word); 

 private:
  std::set<std::string> dictionary;
};



#endif

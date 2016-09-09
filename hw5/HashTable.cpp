// Isaac Goldman
// U14381760
// EC 330 HW 5
// Problem 5

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <list>
#include "HashTable.h"

using namespace std;

// custom constructor reads in strings from a file and instantiates the dictionary member as an stl set of strings
HashTable::HashTable(const char* fileName){

  string word;
  ifstream inputFile(fileName);

  while (inputFile >> word){
    this->dictionary.insert(word);
  }

}

void HashTable::SpellCheck(string word){

  char tempChar;
  string searchWord;
  string lastWord = " ";
  list<string> suggestedSpellings;
  set<string>::iterator setIt = this->dictionary.find(word);
  

  // check if word is spelled correctly and return to console if it is
  if(setIt != this->dictionary.end()){
    cout << *setIt << endl;
  }

  else{

    // check for swapping adjacent characters
    for(int i = 0; i < word.length() - 1; i++){

      searchWord = word;
      tempChar = searchWord[i];
      searchWord[i] = searchWord[i + 1];
      searchWord[i + 1] = tempChar;

      // if there is a match and it is not a repeat, add it to the list of spelling suggestions
      if((this->dictionary.find(searchWord) != this->dictionary.end()) && (searchWord != lastWord)){
	suggestedSpellings.push_back(searchWord);
	lastWord = searchWord;
      }
    } 
  
    
    // check for insertions of single characters
    for(int i = 0; i < word.length(); i++){

      // for each iteration, erase a different character of the word to see if it matches any in the dictionary
      searchWord = word;
      searchWord.erase(searchWord.begin() + i);

      // if there is a match and it is not a repeat, add it to the list of spelling suggestions
      if((this->dictionary.find(searchWord) != this->dictionary.end()) && (searchWord != lastWord)){
	suggestedSpellings.push_back(searchWord);
	lastWord = searchWord;
      }
    }

    // check for deletions of single characters
    for(char c = 'a'; c <= 'z'; c++){
      for(int i = 0; i < word.length() + 1; i++){

	//for each iteration, insert the current letter between each index of the word to see if it matches the dictionary
	searchWord = word;
	searchWord.insert(searchWord.begin() + i, c);

	// if there is a match and it is not a repeat, add it to the list of spelling suggestions
	if((this->dictionary.find(searchWord) != this->dictionary.end()) && (searchWord != lastWord)){
	  suggestedSpellings.push_back(searchWord);
	  lastWord = searchWord;
	}
      }
    }

    // check for replacements of single characters
    for(char c = 'a'; c <= 'z'; c++){
      for(int i = 0; i < word.length(); i++){
	searchWord = word;
	searchWord[i] = c;

	// if there is a match and it is not a repeat, add it to the list of spelling suggestions
	if((this->dictionary.find(searchWord) != this->dictionary.end()) && (searchWord != lastWord)){
	  suggestedSpellings.push_back(searchWord);
	  lastWord = searchWord;
	}
      }
    }

    
    // if no suggestions have been found, print out message and return
    if(suggestedSpellings.empty()){
      cout << "no matches found!" << endl;
    }

    else{
      
      // sort the list of suggested spellings and print to console
      suggestedSpellings.sort();
      for(list<string>::iterator it = suggestedSpellings.begin(); it != suggestedSpellings.end(); ++it){
	cout << *it << endl;
      }
    }
  }
}

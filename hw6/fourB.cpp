#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <list>

using namespace std;

// constructed a trie to hold the dictionary
// used stackoverflow, geektogeek, leetcode and other resources and textbooks to understand and
// implement the trie in a way I could understand and thought was suited to the problem

// each element of the trie will be a trieNode object
class trieNode {

public: 

  trieNode();
  trieNode* children[52]; // 26 letters of the English alphabet * 2 for both upper and lower cases
  bool end_of_word; // returns true if the node marks the end of a word
  bool is_prefix; // returns true if the node is a pre-fix to words
};

// trieNode constructor
trieNode::trieNode(){
  this->end_of_word = false;
  this->is_prefix = false;
}

class Trie {

public: 

  Trie();
  Trie(const char* fileName);
  void insertWord(string newWord);
  bool searchWord(string matchWord);
  bool searchPrefix(string matchPrefix);

private:
  int maxLength;
  trieNode* root;  

};

Trie::Trie(){

  this->root = new trieNode;
  this->maxLength = 0;
}

// custom constructor to create a trie from a specified text file
Trie::Trie(const char* fileName){

  this->root = new trieNode;
  this->maxLength = 0;
  ifstream inputFile(fileName);
  string inputString;

  while(inputFile >> inputString){
    this->insertWord(inputString);
  }

  inputFile.close();
}

void Trie::insertWord(string newWord){
  int length = newWord.length();
  if(newWord[length - 1] == 'n'){
    return;
  }
  int index;
  trieNode* currentNode = this->root;
  for(int i = 0; i < length; i++){
    index = (newWord[i] >= 'A' && newWord[i] <= 'Z') ? newWord[i] - 'A' + 26 : newWord[i] - 'a'; 
    if(!(currentNode->children[index])){
      currentNode->children[index] = new trieNode;
    }
    currentNode->is_prefix = true;
    currentNode = currentNode->children[index];   
  }
  currentNode->end_of_word = true;
  if(length > this->maxLength){
    this->maxLength = length;
  }
}

bool Trie::searchWord(string matchWord){
  int index;
  bool wordFound = false;
  trieNode* currentNode = this->root;

  for(int i = 0; i < matchWord.length(); i++){
    index = (matchWord[i] >= 'A' && matchWord[i] <= 'Z') ? matchWord[i] - 'A' + 26 : matchWord[i] - 'a';
    if(!(currentNode->children[index])){
      return false;
    }
    currentNode = currentNode->children[index];
  }

  wordFound = currentNode->end_of_word;

  return wordFound;
}

bool Trie::searchPrefix(string matchPrefix){
  int index;
  bool prefixFound = false;
  trieNode* currentNode = this->root;
  for(int i = 0; i < matchPrefix.length(); i++){
    index = (matchPrefix[i] >= 'A' && matchPrefix[i] <= 'Z') ? matchPrefix[i] - 'A' + 26 : matchPrefix[i] - 'a';
    if(!(currentNode->children[index])){
      return false;
    }
    currentNode = currentNode->children[index];
  }

  prefixFound = currentNode->is_prefix;

  return prefixFound;

}

// splits the string into substrings and checks if they are in the dictionary
void analyze(string word, int* matchCount, Trie* dictionary){
  string subWord;
  int length = word.length();
  //  cout << length << endl;
  for(int i = 0; i < length; i++){
    for(int j = 1; j <= length - i; j++){

      subWord = word.substr(i,j);
      
      if(dictionary->searchWord(subWord)){
	(*matchCount)++;
	//	cout << subWord << endl;
      }

      if(!(dictionary->searchPrefix(subWord))){
	break;
      }

    }
  }

    
}

void fourB(){

  char inputChar;
  string word;
  int* matchCount = new int(0);
 
  Trie* dictionary = new Trie("dictionary.txt");
  // Trie* dictionary = new Trie("testDictionary.txt");
  //list<string>* matchList = new list<string>;
  
   ifstream inputFile("BigData.txt");
   // ifstream inputFile("SmallData.txt");

   // reads in character by character and concatenates them into a string until a non-letter is reached
  while(inputFile >> noskipws >> inputChar){

    if(isalpha(inputChar)){
      word += inputChar;
      //cout << "word = " << word << endl;
    }

    else {
      if (!(word.empty())){
	analyze(word, matchCount, dictionary);
	word.clear();
      }
    }
  }

  // matchList->sort();
  // matchList->unique();
  cout << *matchCount << endl;

  //  delete matchList;
  delete dictionary;


}

/*
int main(){

  fourB();


  return 0;
}
*/

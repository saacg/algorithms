/////////////////////////////////////////
// Isaac Goldman EC330 Spring 2016 HW1 //
// Problem4b                           //
//                                     //
//                                     //
/////////////////////////////////////////
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string Analyze(string str, int size){
  string returnStr; // will hold the final output of the function
  string* strArr = new string[str.length()]; // array of strings for each substring sequence of the amount of characters based on the input size
  int* strCount = new int[str.length()];
  int maxCount = 0;

  

  if (size > str.length()){  // checks if the size entered is larger than the string entered, if so, it returns the string entered
     returnStr = str;
  }

  else {  
    // iterate through the input string and sort its characters into substrings of the input size 
    for(int i = 0; i < str.length(); i++){    
      for(int j = 0; j < size; j++){
	if(str[i + size - 1]){
	  strArr[i] += str[i + j];
	}
	else{
	  break;
	}
      }
    }

    // counts the frequency of the substrings by iterating through and incrementing the count variable that matches the string's index
    for(int i = 0; i < str.length(); i++){
      for(int j = 0; j < str.length(); j++){
	if(strArr[i][0] && strArr[j][0]){
	  if(strArr[i] == strArr[j]){
	    strCount[i]++;
	  }
	}
	else{
	  break;
	}
      }
    }

    // find max frequency of strings
    for(int i = 0; i < str.length(); i++){
      if(strCount[i]){
	if (strCount[i] > maxCount){
	  maxCount = strCount[i];
	}
      }
      else{
	break;
      }
    }

    // iterate through the array of strings and return the first string that matches the max frequency
    for(int i = 0; i < str.length(); i++){
      if(strCount[i] == maxCount){
	returnStr = strArr[i];
	break;
      }
    }
  }
  return returnStr;
}

  int main(int argc, char* argv[]){
    if (argc != 3){
      cerr << "Invalid input parameters" << endl;
    }
		

    else{
      int size = atoi(argv[2]);
      if(size <= 0 || size >= 10){
	cerr << "Integer must be greater than 0 and smaller than 10" << endl;

      }
		
      else{
	string inputStr = argv[1];
	cout << Analyze (inputStr, size) << endl;
      }	
    }	

    return 0;
  } 

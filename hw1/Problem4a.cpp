//////////////////////////////////////////
// Isaac Goldman EC330 Spring 2016 HW 1 //
// Problem 4a                           // 
//                                      //
//////////////////////////////////////////
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>

using namespace std;

// receives input file of binary numbers and returns decimal sum of numbers
long BinarySum(string FileName){
	long binSum = 0;
	string bin;
	ifstream inputFile(FileName.c_str()); // converts name of file from string to c-string and then opens the file
	
        // while there are still entries in the file, converts the strings to c-strings and then their decimal value, and then adds them to the total sum
	while (inputFile >> bin){
		binSum += strtol(bin.c_str(), NULL, 2);
	}

	return binSum;
}

int main(int argc, char* argv[]){

	if(argc != 2){
		cerr << "Incorrect input parameters" << endl;
	}

	else{
		cout << BinarySum(argv[1]) << endl;
	}

	return 0;
}

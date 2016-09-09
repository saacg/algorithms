#include <iostream> 
#include <string> 


std::string URLify (const char* inputString, int real_length){ 

	std::string urlString = "";
	for(int i = 0; i < real_length; i++){
		char nextChar = inputString[i];
		if(nextChar == ' '){
			urlString += "%20"; 
		} else{
			urlString += nextChar;
		}
	}

	return urlString;

}

int main (int argc, char* argv[]){

	std::cout << URLify(argv[1], std::stoi(argv[2])) << std::endl;

	return 0;
}

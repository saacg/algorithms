#include <iostream>
#include <string>

bool isUnique (std::string str){
	
 	bool returnUnique = true;
	
	for(int i = 0; i < str.length(); i++){
		for(int j = str.length() - 1; j > i; j--){
			if(str[i] == str[j]){
				returnUnique = false;
				break;
			}
		}
	}		

	return returnUnique;
}

int main (int argc, char* argv[]){

	if(isUnique(argv[1])){
		std::cout << "String is unique!" << std::endl;
	} else {
		std::cout << "string is not unique!" << std::endl;
	}

	return 0;

}

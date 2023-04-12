#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

int main(int argc, char **argv){

	if(argc != 2){
		std::cerr << "Zu wenig oder zu viele Argumente" << std::endl;
	}

	std::ifstream infile(argv[1]);
	std::string input;
	int first, next = 0,counter = 0;

	if(!infile.is_open())
		return -1;

	getline(infile,input);
	first = atoi(input.c_str());

	while(getline(infile,input)){
		next = atoi(input.c_str());
		if(next > first)
			counter++;
		first = next;
	}	
	std::cout << "Increases: " << counter << std::endl;
	return 0;
}
